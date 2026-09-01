#include <chrono>
#include <iostream>
#include <string>
#include <utility>

int main() {
    using Clock = std::chrono::steady_clock;
    using Microseconds = std::chrono::microseconds;

  
    std::string copySource(1000000, 'a');
    std::string moveSource(1000000, 'a');

    const auto copyStart = Clock::now();
    std::string copiedString(copySource);
    const auto copyEnd = Clock::now();

    const auto moveStart = Clock::now();
    std::string movedString(std::move(moveSource));
    const auto moveEnd = Clock::now();

    const auto copyTime =
        std::chrono::duration_cast<Microseconds>(copyEnd - copyStart).count();
    const auto moveTime =
        std::chrono::duration_cast<Microseconds>(moveEnd - moveStart).count();

    std::cout << "Copy: " << copyTime << " \xC2\xB5s\n";
    std::cout << "Move: " << moveTime << " \xC2\xB5s\n";

    std::cout << "Copied string size: " << copiedString.size() << '\n';
    std::cout << "Moved string size: " << movedString.size() << '\n';

    return 0;
}
