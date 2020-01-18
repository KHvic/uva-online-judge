#include <bits/stdc++.h>
using namespace std;

int count_bit(int bits){
    int cnt = 0;
    while(bits){
        cnt++;
        bits &= (bits-1);
    }
    return cnt;
}

int get_score(vector<int> dice, int cat) {
    int score = 0;
    if(cat < 7) {
        for(auto& d : dice)
            if(d == cat)
                score += cat;
    } else if(cat == 7) {
        score = accumulate(dice.begin(), dice.end(), 0);
    } else if(cat == 8) {
        if(dice[0] == dice[2] || dice[1] == dice[3] || dice[2] == dice[4])
            score = accumulate(dice.begin(), dice.end(), 0);
    } else if(cat == 9) {
        if(dice[0] == dice[3] || dice[1] == dice[4])
            score = accumulate(dice.begin(), dice.end(), 0);
    } else if(cat == 10) {
        if(dice[0] == dice[4])
            score += 50;
    } else if(cat == 11) {
        vector<bool> hasVal(7);
        for(auto& d : dice)
            hasVal[d] = true;
        for(int i=1;i<=3;i++) {
            if(hasVal[i] && hasVal[i+1] && hasVal[i+2] && hasVal[i+3])
                score = 25;
        }
    } else if(cat == 12) {
        for(int i=0;i<4;i++) {
            if(dice[i]+1 != dice[i+1])
                return 0;
        }
        score += 35;
    } else {
        if(dice[0] == dice[1] && dice[2] == dice[4])
            score += 40;
        else if(dice[0] == dice[2] && dice[3] == dice[4])
            score += 40;
    }
    return score;
}

int dp[1<<13][64];
int path_bonus[1<<13][64];
int path_cat[1<<13][64];

int main() {
    int v;
    while(true) {
        vector<vector<int>> rounds;
        vector<vector<int>> scores;

        for(int i=0;i<13;i++){
            vector<int> dice;
            for(int j=0;j<5;j++){
                if(scanf("%d",&v) == EOF) return 0;
                dice.push_back(v);
            }
            sort(dice.begin(), dice.end());
            rounds.push_back(dice);

            vector<int> score;
            for(int j=0;j<13;j++){
                score.push_back(get_score(dice,j+1));
            }
            scores.push_back(score);
        }
        memset(dp, -1, sizeof dp);
        dp[0][0] = 0;

        for(int i=0;i<13;i++){
            for(int j=0;j<(1<<13);j++)
            if(count_bit(j) == i) {
                for(int k=0;k<13;k++){
                    if(j&(1<<k)) continue;
                    int val = scores[i][k];
                    int bonus = k<6? val : 0;
                    int next_j = j | (1<<k);
                    for(int l=0;l<64;l++){
                        if(dp[j][l] == -1) continue;
                        int next_bonus = min(bonus+l,63);
                        if(dp[next_j][next_bonus] < dp[j][l]+val) {
                            dp[next_j][next_bonus] = dp[j][l]+val;
                            path_bonus[next_j][next_bonus] = l;
                            path_cat[next_j][next_bonus] = k;
                        }
                    }
                }
            }
        }
        int best=0, bonus=0, b_score=0;
        for(int i=0;i<=63;i++){
            int val = dp[(1<<13)-1][i];
            if(val == -1) continue;
            if(i==63) val += 35;
            if(val > best) {
                best = val;
                bonus = i;
                b_score = i==63 ? 35 : 0;
            }
        }
        vector<int> res(15);
        res[14] = best;
        res[13] = b_score;
        int cur = (1<<13)-1;
        int cur_bonus = bonus;
        int rounds_left = 12;
        while(cur){
            int prev_bonus = path_bonus[cur][cur_bonus];
            int prev_cat = path_cat[cur][cur_bonus];
            res[prev_cat] += scores[rounds_left--][prev_cat];
            cur ^= (1<<prev_cat);
            cur_bonus = prev_bonus;
        }
        for(auto it=res.begin(); it!=res.end();it++){
            if(it != res.begin()) printf(" ");
            printf("%d",*it);
        }
        printf("\n");
    }
}
