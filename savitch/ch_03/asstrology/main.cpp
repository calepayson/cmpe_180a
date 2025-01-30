#include <iostream>

const int CAPRICORN_END = 119;
const int AQUARIUS_END = 218;
const int PISCES_END = 320;
const int ARIES_END = 419;
const int TAURUS_END = 520;
const int GEMINI_END = 621;
const int CANCER_END = 722;
const int LEO_END = 822;
const int VIRGO_END = 922;
const int LIBRA_END = 1022;
const int SCORPIO_END = 1121;
const int SAGITTARIUS_END = 1221;

enum Sign {
    AQUARIUS,
    PISCES,
    ARIES,
    TAURUS,
    GEMINI,
    CANCER,
    LEO,
    VIRGO,
    LIBRA,
    SCORPIO,
    SAGITTARIUS,
    CAPRICORN,
};

void print_horoscope(Sign sign) {
    std::cout << "Your horoscope is:\n";
    switch (sign) {
        case Sign::AQUARIUS:
            std::cout << "Aquarius - You're a nerd.\n";
            break;
        case Sign::PISCES:
            std::cout << "Pisces - You're a geek.\n";
            break;
        case Sign::ARIES:
            std::cout << "Ares - You're an ass.\n";
            break;
        case Sign::TAURUS:
            std::cout << "Taurus - You're a dolt.\n";
            break;
        case Sign::GEMINI:
            std::cout << "Gemini - You're a loser.\n";
            break;
        case Sign::CANCER:
            std::cout << "Cancer - You're a sore.\n";
            break;
        case Sign::LEO:
            std::cout << "Leo - You're a cunt.\n";
            break;
        case Sign::VIRGO:
            std::cout << "Virgo - You're a bore.\n";
            break;
        case Sign::LIBRA:
            std::cout << "Libra - You're a liar.\n";
            break;
        case Sign::SCORPIO:
            std::cout << "Scorpio - You're rough.\n";
            break;
        case Sign::SAGITTARIUS:
            std::cout << "Sagittarius - You're a meanie-poo.\n";
            break;
        case Sign::CAPRICORN:
            std::cout << "Capricorn - You're the best noob noob.\n";
            break;
        default:
            std::cout << "I have no idea what's going on with you.\n";
            break;
    }
}

int main() {
    char proceed{'y'};
    while (proceed == 'y' || proceed == 'Y') {
        std::cout << "Please enter your birthday!\n";
        std::cout << "Month (1-12): ";
        int birth_month{};
        std::cin >> birth_month;
        std::cout << "Day (1-31): ";
        int birth_date{};
        std::cin >> birth_date;

        // Convert birthday to an int of the format MMDD
        //  By using a single int, ranges can be found easier
        int date_map = (birth_month * 100) + birth_date;

        if (date_map <= CAPRICORN_END)
            print_horoscope(Sign::CAPRICORN);
        else if (date_map <= AQUARIUS_END)
            print_horoscope(Sign::AQUARIUS);
        else if (date_map <= PISCES_END)
            print_horoscope(Sign::PISCES);
        else if (date_map <= ARIES_END)
            print_horoscope(Sign::ARIES);
        else if (date_map <= TAURUS_END)
            print_horoscope(Sign::TAURUS);
        else if (date_map <= GEMINI_END)
            print_horoscope(Sign::GEMINI);
        else if (date_map <= CANCER_END)
            print_horoscope(Sign::CANCER);
        else if (date_map <= LEO_END)
            print_horoscope(Sign::LEO);
        else if (date_map <= VIRGO_END)
            print_horoscope(Sign::VIRGO);
        else if (date_map <= LIBRA_END)
            print_horoscope(Sign::LIBRA);
        else if (date_map <= SCORPIO_END)
            print_horoscope(Sign::SCORPIO);
        else if (date_map <= SAGITTARIUS_END)
            print_horoscope(Sign::SAGITTARIUS);
        else
            print_horoscope(Sign::CAPRICORN);

        std::cout << "Proceed? (y/n): ";
        std::cin >> proceed;
    }

    return 0;
}
