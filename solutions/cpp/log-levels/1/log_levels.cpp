#include <string>

namespace log_line {

    std::string message(std::string line) {
        
        long unsigned int len_line { line.length() };

        // the message starts +2 of this index
        long unsigned int pos_colon { line.find(":") };
        pos_colon += 2;
        
        // the length of the message is the subtraction below
        std::string content{ line.substr(pos_colon, len_line - pos_colon) };

        return content;
    }

    std::string log_level(std::string line) {

        // first we need to know where "]" is located
        // "[" is always at index 0, so the log level starts at index 1
        long unsigned int pos_right_brack { line.find("]") };

        std::string content{ line.substr(1, pos_right_brack - 1) };

        return content;
    }

    std::string reformat(std::string line) {
        

        std::string message { log_line::message( line ) };
        std::string log_level { log_line::log_level( line ) };

        // reversing the order of the log line
        std::string new_line { message + " (" + log_level + ")" };

        return new_line;
    }

}  // namespace log_line
