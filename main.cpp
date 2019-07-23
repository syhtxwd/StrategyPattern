#include <QCoreApplication>
#include "context.h"
#include "concrete_strategy.h"

//策略模式
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif


int main(int argc, char *argv[])
{
    // 策略之间可以相互替换
    IStrategy *bike = new BikeStrategy();
    IStrategy *car = new CarStrategy();
    IStrategy *train = new TrainStrategy();

    Context *bikeContext = new Context(bike);
    Context *carContext = new Context(car);
    Context *trainContext = new Context(train);

    bikeContext->Travel();
    carContext->Travel();
    trainContext->Travel();

    SAFE_DELETE(bike);
    SAFE_DELETE(car);
    SAFE_DELETE(train);

    SAFE_DELETE(bikeContext);
    SAFE_DELETE(carContext);
    SAFE_DELETE(trainContext);

    getchar();


    return 0;
}
