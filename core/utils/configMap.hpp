#ifndef CONFIGMAPHPP
#define CONFIGMAPHPP

#include "../enum/controlLoop.hpp"
#include "../enum/IAModel.hpp"

namespace CAT{

    class configMap {

        public:
            CAT::IAModel IAModel = CAT::IAModel::tree;
            CAT::controllLoop controllLoop = CAT::controllLoop::sync;
            int timeout = 100;
            
    };


};

#endif