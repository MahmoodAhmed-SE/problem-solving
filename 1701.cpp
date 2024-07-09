class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // [[5,2],[5,4],[10,3],[20,1]]
        // wt: 2 + 
        // ct: 7
        // 1: ct: 0(ct) + if (at) less than ct, 0, else (at) 5(at) + 2(pt) = 7
        //    wt: 7(ct) - 5(at) = 2

        // 2: ct: 7(ct) + if (at) less than ct, 0, else (at) 0(at) + 4(pt) = 11
        //    wt: 11(ct) - 5(at) = 6

        // 3: ct: 11(ct) + 3(pt) = 14
        //    wt: 14(ct) - 10(at) = 4


        // 4: ct: if (at) less than ct, 14(ct), else (at) 20(at) + 1(pt) = 21
        //    wt: 21(ct) - 20(at) = 1


        long wt_total = 0;
        int ct = 0;

        for (const auto &cust : customers) {
            const int *at = &cust[0];
            const int *pt = &cust[1];
            if (*at < ct) {
                ct = ct + *pt;
            } 
            else {
                ct = *at + *pt;
            }

            if (ct >= *at) {
                wt_total += ct - *at;
            }
            else {
                ct = *at + *pt;
                wt_total += *pt - *at;
            }
        }

        return static_cast<double>(wt_total) / customers.size();
    }
};