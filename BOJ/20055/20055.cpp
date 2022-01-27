#include <iostream>
#include <algorithm>

using namespace std;

#define LOAD 0
#define UNLOAD (N - 1)

int N;
int K;
int durability[200];
int has_robot[200];

void rotate_once (int container[]) {
    rotate(container, container + 2 * N - 1, container + 2 * N);
}

void unload () {
    if (has_robot[UNLOAD]) {
        has_robot[UNLOAD] = false;
    }
}

void age (int i) {
    --durability[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; ++i) {
        cin >> durability[i];
    }

    for (int step = 1; true; ++step) {
        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        rotate_once(durability);
        rotate_once(has_robot);

        // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
        unload();

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다. 
        //    로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        for (int i = N - 2; i >= 0; --i) {
            if (!has_robot[i]) continue;
            if (!(!has_robot[i + 1] && durability[i + 1])) continue;

            swap(has_robot[i], has_robot[i + 1]);
            // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
            unload();

            // 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
            age(i + 1);
        }

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (durability[LOAD]) {
            has_robot[LOAD] = true;

            // 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
            age(LOAD);
        }

        // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
        int ctr = 0;
        for (int i = 0; i < 2 * N; ++i) {
            if (!durability[i]) ++ctr;
            if (ctr >= K) {
                cout << step;
                goto end;
            }
        }
    }
end:
    return 0;
}