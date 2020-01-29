import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String[] first = { "f", "g", "s", "f" };
        String[] second = {"h", "f", "f", "b"};
        //配列の中の値が最も存在するものの数を返す。上記の場合、"f"が4つ。
        System.out.println( InterestingParty.bestInvitation(first, second) );
    }
}

class InterestingParty{
    
    static public int bestInvitation(String[] first, String[] second ){
        HashMap<String, Integer> dic = new HashMap<String, Integer>();
        
        //key uniqでhashに展開
        for(int i=0;i<first.length;i++){
            dic.put(first[i], 0);
            dic.put(second[i], 0);
        }
        
        //趣味に対応したkey値をインクリメント
        for(int i=0;i<first.length;i++){
            dic.put( first[i], dic.get(first[i])+1 );
            dic.put( second[i], dic.get(second[i])+1 );
        }
        
        int ans=0;
        //hash内の最大値を取得
        for( String key: dic.keySet() ){
            ans = Math.max(ans, dic.get(key) );
        }
        return ans;
        
    }
}