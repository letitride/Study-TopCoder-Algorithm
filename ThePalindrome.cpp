#include <iostream>
#include <string>
using namespace std;

/*
 * 与えられた文字列の末尾に文字列を追加して回文にすると何文字となるか
 * 両端の文字を中央に向かって順に比較していき、一致しないと1文字分必要とみなす
 * 1文字分必要とみなしたあと、再び両端の文字を比較していく
 */
class ThePalindrome{
    
public:
    static int find(string s){
        //文字列数となるカーソル 両端文字が一致しなかった場合、インクリメントされる
        for(int i=s.size();;i++ ){
            bool flag = true;
            //先頭文字列からサーチするカーソル
            for(int j=0;j<s.size();j++){
                int left = j; //文字列比較対象の左側のindex
                int right = i - j - 1; //文字列比較対象の右側のindex
                //仮想に付け足したインクリメント分は比較しない
                if( right >= s.size()){
                    continue;
                }
                //両端が一致するかの判定
                if( s[left] != s[right] ){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true){return i;}
        }
    }
    
};

int main(void){
    // Your code here!
    int ans = ThePalindrome::find("abccb");
    std::cout << ans << std::endl;
}