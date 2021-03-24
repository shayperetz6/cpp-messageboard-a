#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
#include <stdexcept>
#include <string>
using namespace std;


TEST_CASE("simple check of post and read "){
  ariel::Board board;
    board.post(0,0,Direction::Horizontal,std::string("hello"));
    board.post(0,5,Direction::Horizontal,std::string("friend"));
    board.post(1,0,Direction::Vertical,std::string("cpp"));
    board.post(4,0,Direction::Vertical,"passover");

    //check if the message we post on the board are acuutaly there
    CHECK(board.read(0,0,Direction::Horizontal,5)==std::string("hello"));
    CHECK(board.read(0,5,Direction::Horizontal,6)==std::string("friend"));
    CHECK(board.read(1,0,Direction::Vertical,3)==std::string("cpp"));
    CHECK(board.read(4,0,Direction::Vertical,8)==std::string("passover"));
    //check if in the place we didnt post a message there is underscope
    CHECK(board.read(10,10,Direction::Horizontal,3)==std::string("___"));
    CHECK(board.read(100,100,Direction::Vertical,2)==std::string("__"));

}
TEST_CASE("override Horizontal"){
   ariel::Board board;
    board.post(0,0,Direction::Horizontal,"shay");
    board.post(0,3,Direction::Horizontal,"by");
    board.post(0,5,Direction::Horizontal,"i need a brake");
    board.post(0,12,Direction::Horizontal,"d");
    board.post(1,0,Direction::Horizontal,"i love the sun");
    board.post(1,11,Direction::Horizontal,"sea");
    board.post(2,0,Direction::Horizontal,"the best book");
    board.post(2,4,Direction::Horizontal,"blue");

    //change one letter
    CHECK(board.read(0,0,Direction::Horizontal,4)=="shaby");
    CHECK(board.read(0,5,Direction::Horizontal,13)=="i need a brade");
    //change word
    CHECK(board.read(1,0,Direction::Horizontal,14)=="i love the sea");
    CHECK(board.read(2,0,Direction::Horizontal,13)=="the blue book");
}
TEST_CASE("override Vertical "){
    ariel::Board board;
    board.post(0,0,Direction::Vertical,"shay");
    board.post(3,0,Direction::Vertical,"by");
    board.post(5,0,Direction::Vertical,"i need a brake");
    board.post(12,0,Direction::Vertical,"d");
    board.post(0,1,Direction::Vertical,"i love the sun");
    board.post(11,1,Direction::Vertical,"sea");
    board.post(0,2,Direction::Vertical,"the best book");
    board.post(4,2,Direction::Vertical,"blue");
     //change one letter
    CHECK(board.read(0,0,Direction::Vertical,4)=="shaby");
    CHECK(board.read(5,0,Direction::Vertical,13)=="i need a brade");
    //change word
    CHECK(board.read(0,1,Direction::Vertical,14)=="i love the sea");
    CHECK(board.read(0,2,Direction::Vertical,13)=="the blue book");

}
TEST_CASE("post empty string"){
    ariel::Board board;
    board.post(0,0,Direction::Horizontal,"");
    board.post(1,0,Direction::Horizontal,"");
    board.post(0,1,Direction::Vertical,"");
    board.post(1,1,Direction::Vertical,"");
    CHECK(board.read(0,0,Direction::Horizontal,1)=="_");
    CHECK(board.read(1,0,Direction::Horizontal,1)=="_");
    CHECK(board.read(0,1,Direction::Vertical,1)=="_");
    CHECK(board.read(1,1,Direction::Vertical,1)=="_");   
}
TEST_CASE("reading and override horizontal and vertical"){
    ariel::Board board;
    board.post(0,0,Direction::Horizontal,"i love cpp");
    board.post(1,0,Direction::Vertical,"clean for passover");
    CHECK(board.read(0,0,Direction::Vertical,19)=="iclean for passover");
    board.post(1,1,Direction::Horizontal,"ounter strike is the best game ever");
    CHECK(board.read(1,0,Direction::Horizontal,14)=="counter strike");
    board.post(0,4,Direction::Vertical,"sd");
    CHECK(board.read(1,0,Direction::Horizontal,5)=="couns");
    CHECK(board.read(0,2,Direction::Horizontal,4)=="lose");
   
}

