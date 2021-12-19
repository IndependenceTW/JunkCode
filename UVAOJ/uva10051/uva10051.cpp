#include <bits/stdc++.h>

using namespace std;

typedef struct Box Box;
struct Box {
    int num;
    int color_dir;
};

const string dir[6] = {"front", "back", "left", "right", "top", "bottom"};
int cube[502][6];
int save_height[502][502];
Box tower[502];
Box save_tower[502];
int ans_height;
int n;

void find_highest(int target_cube, int bottom_color, int now_height);

int main() {
    int cases = 1;
    while (cin >> n) {
        if (n <= 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> cube[i][j];
            }
        }

        memset(save_height, 0, sizeof(save_height));
        ans_height = 0;
        find_highest(0, 0, 0);
        printf("Case #%d\n%d\n", cases++, ans_height);
        for(int i = 0; i < ans_height; i++) {
            cout << save_tower[i].num << " " << dir[save_tower[i].color_dir] << endl;
        }
        cout << endl;
    }
    return 0;
}

void find_highest(int target_cube, int bottom_color, int now_height) {
    for(int i = target_cube + 1; i <= n; i++) {
        for(int j = 0;j < 6; j++) {
            if(target_cube == 0 || (cube[i][j] == bottom_color && save_height[i][j] < now_height + 1)) {
                save_height[i][j] = now_height + 1;
                tower[now_height].num = i;
                tower[now_height].color_dir = j;
                if(j % 2 == 1) {
                    find_highest(i, cube[i][j - 1], now_height + 1);
                }
                else {
                    find_highest(i, cube[i][j + 1], now_height + 1);
                }
            }
        }
    }

    if(ans_height <= now_height) {
        ans_height = now_height;
        for(int i = 0; i < now_height; i++) {
            save_tower[i] = tower[i];
        }
    }
}