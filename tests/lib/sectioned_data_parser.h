//
// Created by ne1mnn on 2/1/24.
//

#ifndef DMP_SECTIONED_DATA_PARSER_H
#define DMP_SECTIONED_DATA_PARSER_H

#include <optional>
#include <unordered_map>
#include <string>
#include <sstream>

/**
 * Source parser in format:
 * section = ```
 * [name]:
 *  values
 * ```
 * values = ```[name]: [value]\n``` | values
 * source = section | source
 *
 * @tparam SectionValues - sections container with subscript by key (section name) operator.
 */
template<typename SectionValues>
class sectioned_data_parser {
public: /* Public interface */
    using section_values_t = SectionValues;
    using sections_container_t = std::unordered_map<std::string, section_values_t>;

    explicit sectioned_data_parser(std::istream &input) : _input(input) {}

    sections_container_t parse() {
        sections_container_t result;

        next_line();
        while (_has_next_line) {
            parse_section(result);
        }
        return result;
    }

private: /* Parser methods */
    void parse_section(sections_container_t &sections) {
        // Read section name
        std::string section_name = take_while([](auto ch) { return ch != ':' && ch != END; });
        if (section_name.empty()) {
            return;
        }
        expect(':');

        // Read values for the current section
        section_values_t section_values;
        while (next_line() && test(' ')) {
            take();
            parse_value(section_values);
        }

        // Add the section to the result
        sections[section_name] = section_values;
    }

    void parse_value(section_values_t &section_values) {
        // Read value name
        std::string value_name = take_while([](auto ch) { return ch != ':' && ch != END; });
        if (value_name.empty()) {
            return;
        }
        expect(':');

        // Skip the colon and space
        take_while(isspace);

        // Read the value
        std::string value = take_while([](auto ch) { return ch != END; });
        section_values[value_name] = value;
    }

private: /* Parser helper methods */
    [[nodiscard]] bool test(char expected) const {
        return expected == _current_ch;
    }

    template<typename Callable>
    [[nodiscard]] bool test(Callable pred) const {
        return pred(_current_ch);
    }

    char take() {
        char result = _current_ch;
        _current_ch = has_next_char() ? next_char() : END;
        return result;
    }

    bool take(char expected) {
        if (test(expected)) {
            take();
            return true;
        }
        return false;
    }

    template<typename Callable>
    std::string take_while(Callable pred) {
        std::string result;
        while (test(pred)) {
            result += take();
        }
        return result;
    }

    void expect(char expected) {
        if (!take(expected)) {
            throw std::runtime_error(std::string("Expected '") + expected + "', in line '" + _line + "'");
        }
    }

private: /* Data supply methods */
    bool next_line() {
        std::string new_line;
        _has_next_line = !std::getline(_input, new_line).eof();
        if (!new_line.empty()) {
            _line_pos = 0;
            _line = new_line;
            take();
            return true;
        }
        return false;
    }

    bool has_next_char() const {
        return _line_pos < _line.length();
    }

    char next_char() {
        return _line[_line_pos++];
    }

private: /* Data */
private:
    static constexpr char END = 0;

    std::istream &_input;
    std::string _line{};
    bool _has_next_line{};
    size_t _line_pos{};
    char _current_ch{};
};

#endif //DMP_SECTIONED_DATA_PARSER_H
