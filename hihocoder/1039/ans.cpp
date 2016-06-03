/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-26
*   描    述：
================================================================*/
#include <iostream>
#include <cstring>

using namespace std;

int get_score(char *s) {
    int score = 0;
    bool over = false;
    
    over = false;
    while (!over){
        int i = 0;
        int j = 0;
        
        over = true;
        while (s[j]){
            if (s[j] == s[j + 1]){
                int c = s[j];
                while (s[j] == c){
                    j++;
                    score++;
                }
                over = false;
            }
            else
                s[i++] = s[j++];
        }
        s[i] = 0;
    }
    return score;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
  int n = 0;

  cin >> n;
  while (n--) {
    char s[128] = {0};
    char t[128] = {0};
    int score = 0;
    int len = 0;

    cin >> s;
    len = strlen(s);

    for (int i = 0; i <= len; i++) {
      for (int j = 0; j < 3; j++) {
        memcpy(t, s, i);
        memcpy(t + i + 1, s + i, len - i);
        t[len + 1] = 0;
        t[i] = 'A' + j;
        score = max(score, get_score(t));
      }
    }
    cout << score << endl;
  }
  return 0;
}
