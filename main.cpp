#include <iostream>
#include <limits>
#include <algorithm>
#include "yarn.h"
#include <cassert>

void resetStream();

int main()
{
    YarnSkein test("lace", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    assert(test.getNeedleSize() == 4);
    assert(test.getHookSize() == 4.5);
    YarnSkein test2("Super Fine", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test3("Fine", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test4("Light", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test5("Medium", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test6("Bulky", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test7("Super Bulky", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);
    YarnSkein test8("Jumbo", "blue", 12.3, "Wool, Acrylic, Bamboo, Cotton, Silk", 34.5, 4, 4.5);

    std::string strandWeight, color, fibType;
    double skeinWeight, length, hooksize, needlesize;
    std::cout << "Welcome to the yarn creator!" << std::endl;
    std::cout << "Please start by entering the yarn strand weight. The available weights are lace, super fine, fine, medium, bulky, super bulky, and jumbo:" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, strandWeight);
    std::transform(strandWeight.begin(), strandWeight.end(), strandWeight.begin(), ::toupper);
    while (!YarnSkein::strToWeight.count(strandWeight))
    {
        if (std::cin.eof())
        {
            std::cout << "There was an infinite loop detected and the test ran out of input getting the yarn strand weight. Please check the weight maps and enum to ensure they have all values spelled correctly." << std::endl;
            return 1;
        }
        std::cout << "Please start by entering the yarn strand weight. The available weights are lace, super fine, fine, medium, bulky, super bulky, and jumbo:" << std::endl;
        std::cin >> std::ws;
        std::getline(std::cin, strandWeight);
        std::transform(strandWeight.begin(), strandWeight.end(), strandWeight.begin(), ::toupper);
    }
    std::cout << "Now enter the color: ";
    std::cin >> std::ws;
    std::getline(std::cin, color);
    std::cout << "How long is the yarn in meters? ";
    std::cin >> length;
    while (!std::cin || length < 0)
    {
        if (std::cin.eof())
        {
            std::cout << "There was an infinite loop detected and the test ran out of input getting the length." << std::endl;
            return 1;
        }
        else if (!std::cin)
            resetStream();
        std::cout << "You have entered an invalid value. Yarn length should be greater than 0.";
        std::cout << "How long is the yarn in meters? ";
        std::cin >> length;
    }
    std::cout << "What is the fiber made of? Please enter a comma separated list of fibers from the following list: cotton, bamboo, acrylic, silk, wool" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, fibType); // there is no good way to validate this because of the comma separated list. The class should throw an exception if there is a problem.
    std::cout << "How heavy is the skein in grams? ";
    std::cin >> skeinWeight;
    while (!std::cin || skeinWeight < 0)
    {
        if (std::cin.eof())
        {
            std::cout << "There was an infinite loop detected and the test ran out of input getting the weight." << std::endl;
            return 1;
        }
        else if (!std::cin)
            resetStream();
        std::cout << "You have entered an invalid value. Yarn weight should be greater than 0.";
        std::cout << "How heavy is the skein in grams? ";
        std::cin >> skeinWeight;
    }
    std::cout << "What is the recommended knitting needle size? ";
    std::cin >> needlesize;
    while (!std::cin || needlesize < 0)
    {
        if (std::cin.eof())
        {
            std::cout << "There was an infinite loop detected and the test ran out of input getting the needle size." << std::endl;
            return 1;
        }
        else if (!std::cin)
            resetStream();
        std::cout << "You have entered an invalid value. Yarn needle size should be greater than 0.";
        std::cout << "What is the recommended knitting needle size? ";
        std::cin >> needlesize;
    }
    std::cout << "What is the recommended crochet hook size? ";
    std::cin >> hooksize;
    while (!std::cin || hooksize < 0)
    {
        if (std::cin.eof())
        {
            std::cout << "There was an infinite loop detected and the test ran out of input getting the hook size." << std::endl;
            return 1;
        }
        else if (!std::cin)
            resetStream();
        std::cout << "You have entered an invalid value. Yarn hook size should be greater than 0.";
        std::cout << "What is the recommended crochet hook size? ";
        std::cin >> hooksize;
    }
    YarnSkein yarn(strandWeight, color, length, fibType, skeinWeight, needlesize, hooksize);

    std::string fiberlist = yarn.getFiberList();
    std::cout << fiberlist << std::endl;
    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
