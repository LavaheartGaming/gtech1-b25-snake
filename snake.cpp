#include "snake.hpp"

Snake::Snake(){
    this->head = new Segment();
}

Snake::~Snake(){
    if (this->head != NULL) delete this->head;
}

Segment::Segment(){
    this->next = Segment;
}

Segment::~Segment(){
    if (this->next != NULL) delete Segment;
}

void func(void){
    Snake *s = new Snake();
    delete s;
}

