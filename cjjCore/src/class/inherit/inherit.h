//
// Created by $vf on 2022/5/30.
// Desc:
//

#ifndef CJJCORE_INHERIT_H
#define CJJCORE_INHERIT_H

class Animal{
public:
    int age;
};

class Sheep: virtual public Animal{
};

class Tuo: virtual public Animal{
};

class SheepTuo: public Sheep, public Tuo{
};
#endif //CJJCORE_INHERIT_H
