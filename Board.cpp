#include "Board.hpp"
#include "Direction.hpp"
using namespace std;
#include <iostream>
namespace ariel{
    void Board::post(unsigned int row,unsigned int col,Direction direct,const std::string &str)
    {
        cout<<"posting the add \""<<str<<"\""<<endl;
    }
    std::string Board::read(unsigned int row,unsigned int col,Direction direct, int numOfChars)
    {
        return " ";
    }
    void Board::show()
    {

    }
    Board::Board()
    {

    }
}
