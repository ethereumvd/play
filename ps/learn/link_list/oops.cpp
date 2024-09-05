#include<bits/stdc++.h>
using namespace std ;
class hero
{
    private :
        int health ;
    public :
        hero()//this is a constructor which gets called bts when we say hero king ;
        {
            cout << "constructor called " << "\n" ;  
        }//when we define our own constructor the default constructor is destroyed
        char level;

        void gethealth()//this is a getter 
        {
            cout << health << "\n" ; 
        }
        void sethealth(int h)//this is a setter
        {
            health = h ;
        }
};
int main()
{
    hero saitama ;
    
    cout << "size is: " << sizeof(saitama) << "\n" ;
    saitama.sethealth(999) ;
    saitama.level = 'S' ;
    cout << "health of saitama: " ;
    saitama.gethealth() ;

    //dynamic allocated
    hero* garou = new hero ;

    garou->sethealth(100) ;//or we can do (*garou).sethealth(100) ;

    cout << "health of garou: " ;
    garou->gethealth() ; //or we can do (*garou).gethealth();
    
    hero* king = new hero() ; // basically constructor does king.hero() 

}
