class Particle{
  public:
    int color;//2=blue;1=red;4=green
    float x;
    float y;
    Particle(){}
    Particle(int color,float x,float y){
      this->color=color;
      this->x=x;
      this->y=y;
    }
    void shiftx(float dx){
          x=x+dx/color;
        }
    void shifty(float dy){
          y=y+dy/color;
        }
    int isNorth(float dim){
          if(y<0) return 1;
          else return 0;
        }
    int isSouth(float dim){
          if(y>dim) return 1;
          else return 0;
        }
    int isEast(float dim){
          if(x>dim) return 1;
          else return 0;
        }
    int isWest(float dim){
          if(x<0) return 1;
          else return 0;
        }
    void pup(PUP::er &p){
          p|x;
          p|y;
        }
};
