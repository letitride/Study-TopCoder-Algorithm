import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        //ボトル容量
        int[] c =  {30, 20, 10};
        //ジュース量
        int[] b =  {10, 5, 5};
        //移動元
        int[] f = {0, 1, 2};
        //移動先
        int[] t = {1, 2, 0};

        //移動元から移動先へ配列の順序通りジュースを移した時、ボトル量がどうなっているかを返す
        //移動元が空、または移動先が満杯になった時に次の配列のボトル処理に移る。
        int[] ret = KiwiJuiceEasy.thePouring( c, b, f, t );
        System.out.println(Arrays.toString(ret));
    }
}

class KiwiJuiceEasy{
    
    static public int[] thePouring(int[] capacities, int[] bottles, int[] fromId, int[] toId ){
        for(int i=0;i<fromId.length;i++){
            int f = fromId[i];
            int t = toId[i];
            //toに移せる量。fromの残量またはtoの空き容量の少ない方
            int vol = Math.min(bottles[f], capacities[t] - bottles[t]);
            
            bottles[f] -= vol;
            bottles[t] += vol;
            
        }
        return bottles;
    }
}