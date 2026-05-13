//2588번 곱셈
/*#include <stdio.h>

int main() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);
    
    int b1 = b % 10;
    int b2 = (b / 10) % 10;
    int b3 = b / 100;

    printf("%d\n", a * b1);
    printf("%d\n", a * b2);
    printf("%d\n", a * b3);
    printf("%d\n", a*b);
    
    return 0;
}*/
//11382번 꼬마 정민
/*#include <stdio.h>

int main() {
    long a, b, c;

    scanf("%ld %ld %ld", &a, &b, &c);
    printf("%ld\n", a+b+c);

    return 0;
}*/
//10171번 고양이
/*#include <stdio.h>

int main() {
    printf("\\    /\\\n");
    printf(" )  ( ')\n");
    printf("(  /  )\n");
    printf(" \\(__)|\n");

    return 0;
}*/
//10172번 개
/*#include <stdio.h>

int main() {
    printf("|\\_/|\n");
    printf("|q p|   /}\n");
    printf("( 0 )\"\"\"\\\n");
    printf("|\"^\"`    |\n");
    printf("||_/=\\\\__|\n");
    
    return 0;
}*/
//1330번 두 수 비교하기
/*#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    
    if (a < b) {
        printf("<\n");
    }
    else if (a > b)
    {
        printf(">\n");
    }
    else {
        printf("==\n");
    }
    return 0;
}*/
//9498번 시험 성적
/*#include <stdio.h>

int main() {
    int s;

    scanf("%d", &s);

    if (s>=90 && s<=100) {
        printf("A\n");
    }
    else if (s>=80 && s<=89) {
        printf("B\n");
    }
    else if (s>=70 && s<=79) {
        printf("C\n");
    }
    else if (s>=60 && s<=69) {
        printf("D\n");
    }
    else {
        printf("F\n");
    }

    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10005
#define INF 2000000000

// 간선 구조체
typedef struct {
    int to;
    int flow;   // 이 간선으로 흐르는 유량 (capacity)
    int rev;    // 역방향 간선의 인덱스
    int next;
} Edge;

Edge edges[MAXN * 2];
int head[MAXN];
int edge_cnt = 0;

// 간선 추가 함수 (u -> v 유량 f1, v -> u 유량 f2)
void add_edge(int u, int v, int f1, int f2) {
    // u -> v
    edges[edge_cnt].to = v;
    edges[edge_cnt].flow = f1;
    edges[edge_cnt].rev = edge_cnt + 1;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;

    // v -> u
    edges[edge_cnt].to = u;
    edges[edge_cnt].flow = f2;
    edges[edge_cnt].rev = edge_cnt - 1;
    edges[edge_cnt].next = head[v];
    head[v] = edge_cnt++;
}

// 경로 탐색을 위한 BFS 관련 변수
int parent_edge[MAXN]; // 경로 복원용: 해당 노드로 들어온 간선 인덱스
int visited[MAXN];
int queue[MAXN];

// S에서 T까지의 경로를 구성하는 간선들의 인덱스를 저장할 리스트
int path_edges[MAXN]; 
int path_len = 0;

// S -> T 경로 찾기 (BFS)
int find_path(int S, int T, int N) {
    for (int i = 1; i <= N; i++) visited[i] = 0;
    int front = 0, rear = 0;
    
    queue[rear++] = S;
    visited[S] = 1;
    parent_edge[S] = -1;

    while (front < rear) {
        int u = queue[front++];
        if (u == T) break;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (!visited[v]) {
                visited[v] = 1;
                parent_edge[v] = i; // u -> v 로 가는 간선 인덱스 저장
                queue[rear++] = v;
            }
        }
    }

    if (!visited[T]) return 0; // 경로 없음 (트리라 그럴 일 없음)

    // 경로 역추적 (T에서 S로)
    int curr = T;
    while (curr != S) {
        int e_idx = parent_edge[curr];
        path_edges[path_len++] = e_idx;
        curr = edges[e_idx ^ 1].to; // 역방향 간선의 목적지가 곧 이전 노드
    }
    
    // path_edges는 T->S 순서이므로 뒤집을 필요가 있지만, 
    // 로직 처리는 순서대로 해도 무방하거나 인덱스로 접근하므로 둡니다.
    // 편의상 S->T 순서로 정렬 (path_edges[0]이 S->v1)
    for(int i=0; i<path_len/2; i++){
        int temp = path_edges[i];
        path_edges[i] = path_edges[path_len-1-i];
        path_edges[path_len-1-i] = temp;
    }
    return 1;
}

int main() {
    int N;
    if (scanf("%d", &N) == EOF) return 0;

    // 초기화
    for (int i = 1; i <= N; i++) head[i] = -1;
    
    // 트리의 간선 정보 입력 (N-1개)
    for (int i = 0; i < N - 1; i++) {
        int u, v, f1, f2;
        scanf("%d %d %d %d", &u, &v, &f1, &f2);
        add_edge(u, v, f1, f2);
    }

    int S, T;
    scanf("%d %d", &S, &T);

    // 1. 경로 탐색
    find_path(S, T, N);

    // 2. 초기 최대/최소값 설정
    int ans_min = 0;
    int ans_max = INF;

    // 경로상의 모든 간선에 대해 기본 용량 체크
    for (int i = 0; i < path_len; i++) {
        int e_idx = path_edges[i];
        if (edges[e_idx].flow < ans_max) {
            ans_max = edges[e_idx].flow;
        }
    }

    // 3. 경로상의 중간 노드들(Ports)에 대한 유량 일관성 검사
    // path_edges[i]는 i번째 단계의 간선 (u -> v)
    // 노드 순서: Node[0](S) -> Node[1] -> ... -> Node[len](T)
    // path_edges[0]은 S -> Node[1], path_edges[1]은 Node[1] -> Node[2]
    // 따라서 중간 노드 Node[i]는 path_edges[i-1]로 들어와서 path_edges[i]로 나감
    
    for (int i = 0; i < path_len - 1; i++) {
        int in_edge_idx = path_edges[i];      // P -> v
        int out_edge_idx = path_edges[i+1];   // v -> Next
        
        int v = edges[in_edge_idx].to;        // 현재 검사할 중간 노드
        
        // P -> v 흐름 (in_P)
        int in_P = edges[in_edge_idx].flow;
        // v -> P 흐름 (out_P, 역방향)
        int out_P = edges[in_edge_idx ^ 1].flow;
        
        // v -> Next 흐름 (out_Next)
        int out_Next = edges[out_edge_idx].flow;
        // Next -> v 흐름 (in_Next, 역방향)
        int in_Next = edges[out_edge_idx ^ 1].flow;

        // 노드 v의 총 유동량 F 계산 (들어오는 양 = 나가는 양)
        int F = 0;
        for (int e = head[v]; e != -1; e = edges[e].next) {
            // v에서 나가는 간선의 flow = 해당 이웃으로 나가는 양
            // 유량 보존: 나가는 양의 총합 = 들어오는 양의 총합 = F
            F += edges[e].flow;
        }

        // 제약 조건 1: Max Flow 줄이기
        // S->T 흐름(x)을 제외한 나머지 흐름들이 유효해야 함.
        // 나머지 이웃 k에 대해: in_k + out_k <= F - x
        // 즉, x <= F - (in_k + out_k)
        
        for (int e = head[v]; e != -1; e = edges[e].next) {
            int neighbor = edges[e].to;
            int e_out = e;          // v -> k
            int e_in = e ^ 1;       // k -> v
            
            // 경로상의 이전(P), 다음(Next) 노드는 제외
            int prev_node = edges[in_edge_idx ^ 1].to;
            int next_node = edges[out_edge_idx].to;

            if (neighbor == prev_node || neighbor == next_node) continue;

            int limit = F - (edges[e_in].flow + edges[e_out].flow);
            if (limit < ans_max) {
                ans_max = limit;
            }
        }

        // 제약 조건 2: Min Flow 높이기 (강제 흐름)
        // 1) P에서 들어온 유량(in_P)이 너무 많아, 다른 곳으로 다 못 보내면 Next로 가야 함
        // x >= in_P - (나머지 나갈 곳들의 용량 합)
        // 나머지 나갈 곳 용량 합 = F - out_P - out_Next
        int forced_by_in = in_P - (F - out_P - out_Next);
        if (forced_by_in > ans_min) ans_min = forced_by_in;

        // 2) Next로 내보내야 할 유량(out_Next)이 너무 커서, 다른 곳에서 다 못 채우면 P에서 와야 함
        // x >= out_Next - (나머지 들어올 곳들의 용량 합)
        // 나머지 들어올 곳 용량 합 = F - in_P - in_Next
        int forced_by_out = out_Next - (F - in_P - in_Next);
        if (forced_by_out > ans_min) ans_min = forced_by_out;
    }

    printf("%d %d\n", ans_min, ans_max);

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int n;
    scanf("%d" , &n);
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
        printf("%d\n" , 1);
    }
    else {
        printf("%d\n" , 0);
    }

    return 0;
}*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k1, k2;
    std::cin >> n >> k1 >> k2;

    std::vector<std::vector<int>> s_c_l(n, std::vector<int>(2));
    for (int i = 0; i < n; ++i) {
        std::cin >> s_c_l[i][0] >> s_c_l[i][1];
    }

    std::vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        std::vector<int> arr = s_c_l.front();
        s_c_l.erase(s_c_l.begin());
        int x = n - i - 1;
        for (int j = 0; j < x; ++j) {
            int k = std::abs(arr[0] - s_c_l[j][0]);
            if (arr[1] == s_c_l[j][1] && k <= k1) {
                ans[i] += 1;
                ans[j + n - x] += 1;
            } else if (arr[1] != s_c_l[j][1] && k <= k2) {
                ans[i] += 1;
                ans[j + n - x] += 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}