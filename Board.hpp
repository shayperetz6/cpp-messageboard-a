#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
class Board {
    public:
    Board();
    static void post(unsigned int row,unsigned int col,Direction direct,const std::string &str);
    static std::string read(unsigned int row,unsigned int col,Direction direct,int numOfChar);
   static void show();
    };
}