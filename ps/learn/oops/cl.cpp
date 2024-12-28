#include<iostream>

class log
{
    public :
        const int loglevelerror = 0 ;
        const int loglevelwarning = 1 ;
        const int loglevelinfo = 2 ;
    private :
        int m_loglevel = loglevelinfo ;
    public :
        void setloglevel(int level) {

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

    log.setloglevel(log.loglevelwarning) ;
    log.logerror("error") ;
    log.logwarn("warning") ;
    log.loginfo("yay") ;

    return 0 ;
}
