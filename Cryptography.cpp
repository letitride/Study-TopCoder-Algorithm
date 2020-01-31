#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 与えられた配列内数値をどれか1つ選択し、+1をし、配列内数値の積で最も大きくなる積を返す
 * 配列サイズ分、+1するパターンを計算すれば良い
 */
class Cryptography{
    
public:
    static long long encrypt(vector <int> numbers){
        long long ans = 0;
        for(int i=0; i<numbers.size();i++){
            long long seki = 1;
            for(int j=0; j<numbers.size(); j++){
                if(i == j){
                    seki *= (numbers[j] + 1);
                }else{
                    seki *= (numbers[j]);
                }
            }
            ans = max(ans, seki);
        }
        return ans;
    }
    
    static long long ex_encrypt(vector <int> numbers){
        long long ret = 1;
        sort( numbers.begin(), numbers.end() );
        numbers[0]++;
        for(int i=0; i<numbers.size(); i++){
            ret *= numbers[i];
        }
        return ret;
    }

};

int main(void){
    // Your code here!
    std::vector<int> vec{ 1, 2, 3 };
    long long ans = Cryptography::encrypt(vec);
    ans = Cryptography::encrypt(vec);
    std::cout << ans << std::endl;

}