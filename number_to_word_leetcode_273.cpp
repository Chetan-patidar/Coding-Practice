class Solution {
public:
    string number_conversion(int n){
        if (n == 0)
        return ("Zero");
    long long int limit = 1000000000000, curr_hun, t = 0;

   
    // Array to store the powers of 10
    string multiplier[] = { "", "Trillion", "Billion",
                            "Million", "Thousand" };
        string first_twenty[] = {
        "",        "One",       "Two",      "Three",
        "Four",    "Five",      "Six",      "Seven",
        "Eight",   "Nine",      "Ten",      "Eleven",
        "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

        string tens[]
        = { "",      "Twenty",  "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety" };

     if (n < 20)
        return (first_twenty[n]);

    string answer = "";
     for (long long int i = n; i > 0;
         i %= limit, limit /= 1000) {
 
        // Store the value in multiplier[t], i.e n =
        // 1000000, then r = 1, for multiplier(million), 0
        // for multipliers(trillion and billion)
        curr_hun = i / limit;
 
        // It might be possible that the current multiplier
        // is bigger than your number
        while (curr_hun == 0) {
 
            // Set i as the remainder obtained when n was
            // divided by the limit
            i %= limit;
 
            // Divide the limit by 1000, shifts the
            // multiplier
            limit /= 1000;
 
            // Get the current value in hundreds, as
            // English system works in hundreds
            curr_hun = i / limit;
 
            // Shift the multiplier
            ++t;
        }
 
        // If current hundred is greater than 99, Add the
        // hundreds' place
        if (curr_hun > 99)
            answer += (first_twenty[curr_hun / 100]
                       + " Hundred ");
 
        // Bring the current hundred to tens
        curr_hun = curr_hun % 100;
 
        // If the value in tens belongs to [1,19], add using
        // the first_twenty
 
        if (curr_hun > 0 && curr_hun < 20)
            answer += (first_twenty[curr_hun] + " ");
 
        // If curr_hun is now a multiple of 10, but not 0
        // Add the tens' value using the tens array
        else if (curr_hun % 10 == 0 && curr_hun != 0)
            answer += (tens[curr_hun / 10 - 1] + " ");
 
        // If the value belongs to [21,99], excluding the
        // multiples of 10 Get the ten's place and one's
        // place, and print using the first_twenty array
 
        else if (curr_hun > 20 && curr_hun < 100)
            answer += (tens[curr_hun / 10 - 1] + " "
                       + first_twenty[curr_hun % 10] + " ");
 
        // If Multiplier has not become less than 1000,
        // shift it
        if (t < 4)
            answer += (multiplier[++t] + " ");
    }
    return (answer);



    }

    string numberToWords(int num) {
        string answer = number_conversion(num);
        int n = answer.size();
        if(answer[n-1]==' ')
            answer.pop_back();
        return answer;
    }
};
