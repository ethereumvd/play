#include<iostream>

enum example : unsigned char //an enum has to be integer,it is 32 bit unsigned integer by default
{
    a='a', b, c 
};
char A = 'z' ;

class log
{
    public :
        enum level 
        {
            loglevelerror =0 , loglevelwarning , loglevelinfo 
        };
    private :
        level m_loglevel = loglevelinfo ;
    public :
        void setloglevel(level level) {

            m_loglevel = level ;

        }

        void logwarn(const char* message) {

            if(m_loglevel >= loglevelwarning) std::cout <<"WARNING"<<message << "\n" ;

        }

        void logerror(const char* message) {

            if(m_loglevel >= loglevelerror) std::cout <<"ERROR"<<message << "\n" ;

        }

        void loginfo(const char* message) {

            if(m_loglevel >= loglevelinfo) std::cout <<"INFO"<< message <<"\n";

        } 

};

int main() {

    log log ;

    log.setloglevel(log::loglevelwarning) ;
    log.logerror("error") ;
    log.logwarn("warning") ;
    log.loginfo("yay") ;

    example value = b ;
    std::cout << A << " " << b << " " << c ; 

    if(value==b){
        //do something 
        std::cout << "the value is in fact b" << "\n" ;
    }


    return 0 ;
}
