#include "./core/utils/configMap.hpp"
#include <iostream>

int main(){

    CAT::configMap configmap = CAT::configMap{};

    configmap.IAModel = CAT::IAModel::cnn;

    std::cout <<  configmap.timeout << std::endl;

}