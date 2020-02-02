#include <iostream>
#include <vector>
using namespace std;

/**
 * 与えられた2以上の基数で表現された3桁までの数値がnの倍数の時、
 * 各桁の総和も必ずnの倍数となる数値nを返す
 */
class InterestingDigits{
    
public:
    static vector<int> digits(int base){
        vector<int> ans;
        
        for( int n=2; n<base; n++ ){
            //std::cout << "check:" << std::endl;
            //std::cout << n << std::endl;
            bool ok = true;
            
            for(int k1=0; k1<base; k1++){
                for(int k2=0; k2<base; k2++){
                    for(int k3=0; k3<base; k3++){
                        //チェック対象を10進数に
                        int dec = k3*base*base + k2*base + k1;
                        //対象がnの倍数の時、対象の桁の総和がnの倍数でない場合、nを除外
                        if( dec % n == 0 && (k1 + k2 + k3) % n != 0 ){
                            ok = false;
                            break;
                        }
                    }
                    if(ok == false){break;}
                }
                if(ok == false){break;}
            }
            //すべてのloopが通過できたnが合格
            if( ok == true ){ 
                ans.push_back(n); }
        }
        return ans;
    }
    
};

int main(void){
    // Your code here!
    vector<int> ans = InterestingDigits::digits(10);
    for(auto a: ans){
        std::cout << a << std::endl;
    }
}