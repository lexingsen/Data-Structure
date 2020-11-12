/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-25 17:06:48
 */
#include <iostream>
#include <string>
#include <chrono>
#include <cstring>
#include <openssl/md5.h>
class TimeGuard{
public:
    std::string name;
    std::chrono::high_resolution_clock::time_point start;
    TimeGuard(std::string _name){
        name = _name;
        start = std::chrono::high_resolution_clock::now();
    }
    ~TimeGuard(){
        std::cout <<name<<" cost time : “<<std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now() - start).count()<<” ms"<< std::endl;
    }
};
uint64_t BKDRHash(const char *p, size_t len, uint64_t seed){
    for(size_t i = 0; i < len; ++i){
        const char ch = p[i];
        seed = seed * 131 + ch;
    }
    return seed;
}
long MD5Hash(const char *p,size_t len){
    long hashValue = 0;
    unsigned char x[16];
    bzero(x,sizeof(x));
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5,p,len);
    MD5_Final(x,&md5);
    for(size_t i = 0; i < 4; ++i){
        hashValue += ((long)(x[i*4+3]&0xff) << 24) |
                     ((long)(x[i*4+2]&0xff) << 16) |
                     ((long)(x[i*4+1]&0xff) << 8) |
                     ((long)(x[i*4+0]&0xff) << 0);
    }
    return hashValue;
}
int main(){
    const char * p1 = “sadafa s432535333bbbbbbbbbb4b54235b2aasfa df321”;
    const char * p2 = “WWWWfa323567853453546356346346 asfa df32gs1”;
    const char * p3 = “sa346346346436czczc2342345344655…dafa saasfa df321”;
    int nRepeat = 100000;
    {
        uint64_t seed = 123124132;
        TimeGuard _(“BKDRHash”);
        for(int i = 0; i < nRepeat; ++i){
            auto v = BKDRHash(p1,strlen(p1),seed);
            auto v1 = BKDRHash(p2,strlen(p2),seed);
            auto v2 = BKDRHash(p3,strlen(p3),seed);
        }
    }
    {
        TimeGuard _(“MD5Hash”);
        for(int i = 0; i < nRepeat; ++i){
            auto v = MD5Hash(p1,strlen(p1));
            auto v1 = MD5Hash(p2,strlen(p2));
            auto v2 = MD5Hash(p3,strlen(p3));
        }
    }
}