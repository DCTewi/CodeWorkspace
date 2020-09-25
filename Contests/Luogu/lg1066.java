import java.util.*;
import java.math.*;

public class lg1066 {

    public static int MAXN = 512 + 5;

    public static BigInteger[][] c = new BigInteger[MAXN][MAXN];

    public static void get_c(BigInteger uplimit)
    {
        c[0][0] = c[1][0] = c[1][1] = BigInteger.ONE;
        for (int i = 2; i <= uplimit.intValue(); i++)
        {
            c[i][0] = BigInteger.ONE;
            for (int j = 1; j <= i; j++)
            {
                c[i][j] = new BigInteger(c[i][j - 1].add(c[i - 1][j - 1]).toString());
            }
        }
    }

    public static void main(String arg[])
    {
        Scanner cin = new Scanner(System.in);

        BigInteger k = cin.nextBigInteger(), n = cin.nextBigInteger(), two = BigInteger.valueOf(2);

        BigInteger len = n.divide(k), res = n.mod(k), maxx = two.pow(k.intValue());

        get_c(maxx);

        BigInteger ans = BigInteger.ZERO;

        for (int i = 2; i <= len.intValue(); i++)
        {
            if (i > maxx.intValue() - 1) break;
            ans.add(c[maxx.intValue() - 1][i]);
        }

        long r = (two.pow(res.intValue()).intValue());
        for (int i = 1; i < r; i++)
        {
            ans.add(c[maxx.intValue() - i][len.intValue()]);
        }

        cin.close();
        System.out.println(ans);
    }
}