#include <iostream>
#include <queue>
#include <climits>

#define MAX_SIZE 10000

using namespace std;

enum LOCATION {LEFT, RIGHT};    // 두 정박장은 강을 기준으로 왼쪽(left), 오른쪽(right)으로 구분한다.

int M, t, N;    // TODO: int ??
struct guest {
    int guest_no;
    int arrival_time;
};
queue<guest> location_queue[2];
queue<int> boat_queue;
int burst_time[MAX_SIZE];

guest get_pending_guest_at(LOCATION location) {
    if(location_queue[location].size()) return location_queue[location].front();
    else return {INT_MAX, INT_MAX};
}

int main() {
    cin >> M >> t >> N;

    for(int guest_no = 0; guest_no < N; ++guest_no) {
        int arrival_time;
        string dest_location;
        
        cin >> arrival_time >> dest_location;

        LOCATION guest_location;
        if(dest_location == "left")   guest_location = LEFT;
        else                          guest_location = RIGHT;

        location_queue[guest_location].push({guest_no, arrival_time});
    }

    LOCATION cur_location = LEFT;  // 제일 처음에는 나룻배가 왼쪽 정박장에 위치해 있다.
    for(int time = 0; location_queue[LEFT].size() || location_queue[RIGHT].size();) {
        // 만약 기다리던 손님이 없다면, 나룻배가 그 정박장에서 다음 손님을 기다리게 된다. 만약 기다리던 중 반대 쪽 정박장에 손님이 도착하면, 그 쪽 정박장으로 이동하게 된다.
        guest guest_here = get_pending_guest_at(cur_location);
        if(guest_here.arrival_time > time) {     
            guest guest_across = get_pending_guest_at((LOCATION)!cur_location);
            if(guest_across.arrival_time < guest_here.arrival_time) {
                time = max(time, guest_across.arrival_time) + t;  // 한 쪽 정박장에서 다른 쪽 정박장으로 이동하는데 양쪽 방향 모두 t만큼의 시간이 걸린다.
                cur_location = (LOCATION)(1 - cur_location);  
            }
            else {
                time = guest_here.arrival_time;
            }
        }

        // 그 정박장에서 기다리고 있던 손님들을 배에 태울 수 있는 데까지 태운다. 손님이 배에 타는데 드는 시간은 없다고 가정하며, 가장 오래 기다린 사람이 먼저 배를 타게 된다.
        for(int i = 0; i < M; ++i) {    // 이 나룻배는 한번에 최대 M명의 사람을 태울 수 있으며
            if(!location_queue[cur_location].size()) break;
            guest guest_to_load = location_queue[cur_location].front();

            if(guest_to_load.arrival_time > time) break;
            location_queue[cur_location].pop();
            boat_queue.push(guest_to_load.guest_no);
        }

        
        // 나룻배가 어떤 정박장에 도착하게 되면, 그 정박장으로 가고자 하는 사람들을 우선 모두 내려준다.
        time += t;
        cur_location = (LOCATION)!cur_location;

        while(boat_queue.size()) {
            burst_time[boat_queue.front()] = time;
            boat_queue.pop();
        }
    }

    for(int i = 0; i < N; ++i) {
        cout << burst_time[i] << '\n';
    }
    return 0;
}