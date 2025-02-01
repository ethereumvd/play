class entity {

protected: //own class and all classes derieved from this class can access
  int x, y;

public:
    entity (){
        x = 0 ; y = 0 ;
    }

};

class player : public entity {
public :
    player() {
        x = 3 ;
    }

};

int main() { 
    return 0;
}
