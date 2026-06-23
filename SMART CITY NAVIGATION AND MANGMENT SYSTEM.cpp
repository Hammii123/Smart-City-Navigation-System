//Wah Cantt Smart Navigation and Management System

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;




template <typename T>
class StackNode
{
public:
    T data;
    StackNode* next;

    StackNode(T val)
    {
        data = val;
        next = nullptr;
    }
};


template <typename T>
class Stack
{
private:
    StackNode<T>* top;

public:
    Stack()
    {
        top = nullptr;
    }

    // ================= EMPTY CHECK =================
    bool empty()
    {
        return top == nullptr;
    }

    // ================= PUSH =================
    void push(T val)
    {
        StackNode<T>* n = new StackNode<T>(val);
        n->next = top;
        top = n;
    }

    // ================= POP =================
    void pop()
    {
        if(empty())
        {
            cout << "Stack Empty\n";
            return;
        }

        StackNode<T>* temp = top;
        top = top->next;
        delete temp;
    }

    // ================= TOP ELEMENT =================
    T peek()
    {
        if(empty())
            throw "Stack Empty";
        return top->data;
    }

    // ================= SIZE =================
    int size()
    {
        int count = 0;
        StackNode<T>* temp = top;

        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // ================= CLEAR STACK =================
    void clear()
    {
        while(!empty())
            pop();
    }

    // ================= DESTRUCTOR =================
    ~Stack()
    {
        clear();
    }
};


template <typename T>
class PriorityQueue
{
private:
    vector<T> heap;

    bool compare(T a, T b)
    {
        return a.first < b.first; // min heap based on distance
    }

    void heapifyUp(int i)
    {
        while(i > 0)
        {
            int parent = (i - 1) / 2;

            if(compare(heap[i], heap[parent]))
            {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else break;
        }
    }

    void heapifyDown(int i)
    {
        int n = heap.size();

        while(true)
        {
            int smallest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n && compare(heap[left], heap[smallest]))
                smallest = left;

            if(right < n && compare(heap[right], heap[smallest]))
                smallest = right;

            if(smallest != i)
            {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else break;
        }
    }

public:

    void push(T val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    T top()
    {
        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }
};   







template <typename T>
class QueueNode
{
public:
    T data;
    QueueNode* next;

    QueueNode(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    // ================= EMPTY CHECK =================
    bool empty()
    {
        return front == nullptr;
    }

    // ================= ENQUEUE =================
    void enqueue(T val)
    {
        QueueNode<T>* n = new QueueNode<T>(val);

        if(rear == nullptr)
        {
            front = rear = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    // ================= DEQUEUE =================
    void dequeue()
    {
        if(empty())
        {
            cout << "Queue Empty\n";
            return;
        }

        QueueNode<T>* temp = front;
        front = front->next;

        if(front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // ================= FRONT ELEMENT =================
    T Front()
    {
        if(empty())
            throw "Queue Empty";
        return front->data;
    }

    // ================= REAR ELEMENT =================
    T Rear()
    {
        if(empty())
            throw "Queue Empty";
        return rear->data;
    }

    // ================= SIZE =================
    int size()
    {
        int count = 0;
        QueueNode<T>* temp = front;

        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // ================= CLEAR QUEUE =================
    void clear()
    {
        while(!empty())
            dequeue();
    }

    // ================= DESTRUCTOR =================
    ~Queue()
    {
        clear();
    }
};




template <typename T>
class ListNode
{
public:
    T data;
    ListNode* next;

    ListNode(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
private:
    ListNode<T>* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // ================= EMPTY CHECK =================
    bool isEmpty()
    {
        return head == nullptr;
    }

    // ================= INSERT (AT END) =================
    void insert(T val)
    {
        ListNode<T>* n = new ListNode<T>(val);

        if(head == nullptr)
        {
            head = n;
            return;
        }

        ListNode<T>* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = n;
    }

    // ================= SEARCH =================
    bool search(T val)
    {
        ListNode<T>* temp = head;

        while(temp != nullptr)
        {
            if(temp->data == val)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // ================= DELETE NODE =================
    void deleteNode(T val)
    {
        if(head == nullptr)
        {
            cout << "List Empty\n";
            return;
        }

        // if head node is to be deleted
        if(head->data == val)
        {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode<T>* curr = head;
        ListNode<T>* prev = nullptr;

        while(curr != nullptr && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        if(curr == nullptr)
        {
            cout << "Value not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // ================= SIZE =================
    int size()
    {
        int count = 0;
        ListNode<T>* temp = head;

        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // ================= DISPLAY =================
    void display()
    {
        if(head == nullptr)
        {
            cout << "List Empty\n";
            return;
        }

        ListNode<T>* temp = head;

        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // ================= GET HEAD =================
    ListNode<T>* getHead()
    {
        return head;
    }

    // ================= CLEAR LIST =================
    void clear()
    {
        while(head != nullptr)
        {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ================= DESTRUCTOR (VERY IMPORTANT) =================
    ~LinkedList()
    {
        clear();
    }
};














//TrafficSignal Class

class TrafficSignalQueue
{
private:
    vector<string> signals;
    int front;
    int rear;
    int size;
    int capacity;

public:
    TrafficSignalQueue(int cap)
    {
        capacity = cap;
        signals.resize(capacity);

        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void addSignal(string signal)
    {
        if(isFull())
        {
            cout << "Signal Queue Full\n";
            return;
        }

        rear = (rear + 1) % capacity;

        signals[rear] = signal;

        size++;
    }

   void nextSignal()
{
    if(isEmpty())
    {
        cout << "No Signals Available\n";
        return;
    }

    cout << "\n🟢 GREEN SIGNAL: " << signals[front] << endl;

    front = (front + 1) % capacity;
    size--;   // ✔ IMPORTANT FIX
}

    void displaySignals()
    {
        if(isEmpty())
        {
            cout << "No Signals\n";
            return;
        }

        cout << "\n🚦 Traffic Signals:\n";

        int i = front;

        for(int count = 0; count < size; count++)
        {
            cout << signals[i] << endl;

            i = (i + 1) % capacity;
        }
    }
};
//________________________________________
//Complaint Class
class Complaint
{
private:
    int id;
    string citizen;
    string issue;

public:
    Complaint() {}

    Complaint(int i, string c, string is)
    {
        id = i;
        citizen = c;
        issue = is;
    }

    void display()
    {
        cout << "Complaint ID: " << id << endl;
        cout << "Citizen: " << citizen << endl;
        cout << "Issue: " << issue << endl;
    }
};
//________________________________________
//NavigationSystem Class
class NavigationSystem
{
private:
   Stack<string> history;

public:
    void addHistory(string route)
{
    history.push(route);
}

void showHistory()
{
    if(history.empty())
    {
        cout << "\nNo Navigation History\n";
        return;
    }

    Stack<string> temp;   // ✔ custom stack

    cout << "\n🛣️ Navigation History:\n";

    while(!history.empty())
    {
        string val = history.peek();
        cout << val << endl;

        temp.push(val);
        history.pop();
    }

    // restore original stack
    while(!temp.empty())
    {
        history.push(temp.peek());
        temp.pop();
    }
}
void undoLastRoute()
{
    if(history.empty())
    {
        cout << "\nNo Route To Remove\n";
        return;
    }

    cout << "\n❌ Removed Route: "
         << history.peek() << endl;

    history.pop();
}
};
//________________________________________
//Hospital Class
class Hospital
{
private:
    string name;
    string location;

public:
    Hospital() {}

    Hospital(string n, string l)
    {
        name = n;
        location = l;
    }

    void display()
    {
        cout << "Hospital: " << name << endl;
        cout << "Location: " << location << endl;
    }
};
//________________________________________
//PoliceStation Class
class PoliceStation
{
private:
    string name;

public:
    PoliceStation()   // ✅ REQUIRED FIX
    {
        name = "";
    }

    PoliceStation(string n)
    {
        name = n;
    }

    void display()
    {
        cout << "Police Station: " << name << endl;
    }
};




//GRAPH IMPLEMENTATION
//Adjacency List Based Graph
class Graph
{
private:
    struct Edge
    {
        string to;
        string roadName;
        double km;
    };

    unordered_map<string, vector<Edge>> adj;

    void DFSUtil(string node, unordered_map<string,bool> &vis)
    {
        vis[node] = true;
        cout << node << " -> ";

        for(auto &e : adj[node])
        {
            if(!vis[e.to])
                DFSUtil(e.to, vis);
        }
    }

public:
    // ================= ADD ROAD =================
    void addRoad(string from, string to, string roadName, double km)
    {
        adj[from].push_back({to, roadName, km});
        adj[to].push_back({from, roadName, km});
    }

    // ================= DISPLAY GRAPH =================
    void display()
    {
        cout << "\n🏙️ WAH CANTT ROAD NETWORK\n";

        for(auto &node : adj)
        {
            cout << "\n📍 " << node.first << ":\n";

            for(auto &e : node.second)
            {
                cout << "   → " << e.to
                     << " via " << e.roadName
                     << " (" << e.km << " km)\n";
            }
        }
    }

    // ================= BFS =================
   void BFS(string start)
{
    unordered_map<string,bool> vis;

    Queue<string> q;   // custom queue

    vis[start] = true;
    q.enqueue(start);

    cout << "\n🚶 BFS Traversal:\n";

    while(!q.empty())
    {
        string node = q.Front();
        q.dequeue();

        cout << node << " ";

        for(auto &e : adj[node])
        {
            if(!vis[e.to])
            {
                vis[e.to] = true;
                q.enqueue(e.to);
            }
        }
    }

    cout << endl;
}

    // ================= DFS =================
    void DFS(string start)
    {
    	unordered_map<string,bool> vis;
        cout << "\n🧠 DFS Traversal:\n";
        DFSUtil(start, vis);
        cout << endl;
}
    // ================= DIJKSTRA (REAL ROUTE) =================
    void dijkstra(string start, string end)
    {
        unordered_map<string,double> dist;
        unordered_map<string,string> parent;

        for(auto &node : adj)
            dist[node.first] = 1e9;

        dist[start] = 0;

       PriorityQueue<pair<double,string>> pq;

        pq.push({0, start});

        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            string u = cur.second;

            for(auto &e : adj[u])
            {
                string v = e.to;
                double w = e.km;

                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\n🚗 Shortest Distance: " << dist[end] << " km\n";

        // path reconstruction
        vector<string> path;
        string cur = end;

        while(cur != start)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(start);

        reverse(path.begin(), path.end());

        cout << "🛣️ Route: ";
        for(auto &x : path)
            cout << x << " -> ";

        cout << "END\n";
    }
};



//TRIE IMPLEMENTATION
class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;

        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

   void insert(string word)
{
    TrieNode* current = root;

    for(char c : word)
    {
        c = tolower(c);

        // ignore special characters
        if(c < 'a' || c > 'z')
            continue;

        int index = c - 'a';

        if(current->children[index] == NULL)
        {
            current->children[index] = new TrieNode();
        }

        current = current->children[index];
    }

    current->isEnd = true;
}

   bool search(string word)
{
    TrieNode* current = root;

    for(char c : word)
    {
        c = tolower(c);

        // ignore special characters
        if(c < 'a' || c > 'z')
            continue;

        int index = c - 'a';

        if(current->children[index] == NULL)
            return false;

        current = current->children[index];
    }

    return current->isEnd;
}
};

class System
{
private:
    Graph city;
    TrafficSignalQueue trafficSignals;
    unordered_map<string, string> entityType;   // name → type
unordered_map<string, string> entityInfo;   // name → full details
Trie searchIndex;
  LinkedList<Hospital> hospitals;
LinkedList<PoliceStation> policeStations;
vector<Complaint> complaints;
    NavigationSystem nav;

public:
System() : trafficSignals(10)
{
}
    Graph& getGraph()
    {
        return city;
    }
    
    void addTrafficSignal(string name)
{
    trafficSignals.addSignal(name);
}

void showSignals()
{
    trafficSignals.displaySignals();
}

void nextTrafficSignal()
{
    trafficSignals.nextSignal();
}
    
    void storeEntity(string name, string type, string info)
{
    entityType[name] = type;
    entityInfo[name] = info;
}
 void searchCity(string key)
{
    if(searchIndex.search(key))
    {
        cout << "\n✔ FOUND IN CITY SYSTEM: " << key << endl;

        cout << "Type: " << entityType[key] << endl;
        cout << "Details: " << entityInfo[key] << endl;
    }
    else
    {
        cout << "\n❌ NOT FOUND: " << key << endl;
    }
}

    // ================= ADMIN FUNCTIONS =================
 void addRoad(string u, string v, string name, double km)
{
    city.addRoad(u, v, name, km);

    searchIndex.insert(name);
    searchIndex.insert(u);
    searchIndex.insert(v);

    storeEntity(name, "Road",
                "Connects " + u + " <-> " + v +
                " | Distance: " + to_string(km) + " km");
}
   void addHospital(string name, string loc)
{
   hospitals.insert(Hospital(name, loc));
    searchIndex.insert(name);
    searchIndex.insert(loc);

    storeEntity(name, "Hospital", "Location: " + loc);
}

   void addPoliceStation(string name)
{
   policeStations.insert(PoliceStation(name));
    searchIndex.insert(name);

    storeEntity(name, "Police Station", "Security Unit");
}
    

    void addComplaint(int id, string citizen, string issue)
    {
        complaints.push_back(Complaint(id, citizen, issue));
    }

    void showHospitals()
    {
        cout << "\n🏥 Hospitals:\n";
        for(ListNode<Hospital>* temp = hospitals.getHead(); temp != nullptr; temp = temp->next)
{
    temp->data.display();
}
    }

    void showPolice()
    {
        cout << "\n🚓 Police Stations:\n";
        for(ListNode<PoliceStation>* temp = policeStations.getHead(); temp != nullptr; temp = temp->next)
{
    temp->data.display();
}
    }

    void showComplaints()
    {
        cout << "\n📢 Complaints:\n";
        for(auto &c : complaints)
            c.display();
    }

    // ================= USER FUNCTIONS =================
    void showMap()
    {
        city.display();
    }

    void bfs(string start)
    {
        city.BFS(start);
        nav.addHistory("BFS from " + start);
    }

    void dfs(string start)
    {
        city.DFS(start);
        nav.addHistory("DFS from " + start);
    }

    void shortestPath(string a, string b)
    {
        city.dijkstra(a, b);
        nav.addHistory("Shortest path: " + a + " -> " + b);
    }

  void showHistory()
{
    nav.showHistory();
}
    void undoRoute()
{
    nav.undoLastRoute();
}
};








void adminMenu(System &sys)
{
    int choice;

    while(true)
    {
        cout << "\nADMIN PANEL";
        cout << "\n1. Add Road";
        cout << "\n2. Add Hospital";
        cout << "\n3. Add Police Station";
        cout << "\n4. Add Traffic Signal";
        cout << "\n5. View Complaints";
        cout << "\n6. View Map";
        cout << "\n7. Exit Admin";
        cout << "\nChoice: ";
        cin >> choice;

        if(choice == 1)
        {
            string u,v,name;
            double km;

            cout << "From To RoadName KM: ";
            cin >> u >> v >> name >> km;

            sys.addRoad(u,v,name,km);
        }

        else if(choice == 2)
        {
            string n,l;
            cout << "Hospital Name Location: ";
            cin >> n >> l;

            sys.addHospital(n,l);
        }

        else if(choice == 3)
        {
            string n;
            cout << "Police Station Name: ";
            cin >> n;

            sys.addPoliceStation(n);
        }
else if(choice == 4)
{
    string s;

    cout << "Signal Name: ";
    cin >> s;

    sys.addTrafficSignal(s);
}
        else if(choice == 5)
        {
            sys.showComplaints();
        }

        else if(choice == 6)
        {
            sys.showMap();
        }

        else break;
    }
}


void userMenu(System &sys)
{
    int choice;

    while(true)
    {
        cout << "\n USER PANEL";
        cout << "\n1. View Map";
        cout << "\n2. BFS Traversal";
        cout << "\n3. DFS Traversal";
        cout << "\n4. Shortest Path";
        cout << "\n5. View Hospitals";
        cout << "\n6. View Police Stations";
        cout << "\n7. View Navigation History";
        cout << "\n8. Search  Any Thing in City System";
        cout << "\n9. View Traffic Signals";
         cout << "\n10. Next Green Signal";
         cout << "\n11. Undo Last Route";
        cout << "\n12. Exit User";
        cout << "\nChoice: ";
        cin >> choice;

        string a,b;

        if(choice == 1)
        {
            sys.showMap();
        }

        else if(choice == 2)
        {
            cout << "Start: ";
            cin >> a;
            sys.bfs(a);
        }

        else if(choice == 3)
        {
            cout << "Start: ";
            cin >> a;
            sys.dfs(a);
        }

        else if(choice == 4)
        {
            cout << "From To: ";
            cin >> a >> b;
            sys.shortestPath(a,b);
        }

        else if(choice == 5)
        {
            sys.showHospitals();
        }

        else if(choice == 6)
        {
            sys.showPolice();
        }

        else if(choice == 7)
        {
            sys.showHistory();
        }
        else if(choice == 8)
        
{
    string key;
    cout << "Enter name to search: ";
    cin >> key;

    sys.searchCity(key);
}
else if(choice == 9)
{
    sys.showSignals();
}

else if(choice == 10)
{
    sys.nextTrafficSignal();
}
else if(choice == 11)
{
    sys.undoRoute();
}
        else break;
    }
}


//MAIN FUNCTION
int main()
{
    System sys;


// ===== ROADS (ADD FIRST) =====
sys.addRoad("GT_Road_Wah_Cantt", "Wah_Model_Town", "GT_Main_Road", 3.2);
sys.addRoad("GT_Road_Wah_Cantt", "Wah_Cantt_Railway_Station", "Station_Road", 2.5);

sys.addRoad("Wah_Model_Town", "Phase_1", "Model_Town_Link", 1.8);
sys.addRoad("Wah_Model_Town", "Phase_2", "Sector_Road", 2.4);

sys.addRoad("Phase_1", "POF_Hospital", "Hospital_Road", 2.0);
sys.addRoad("Phase_2", "Taxila_Road", "Highway_Link", 3.5);

sys.addRoad("Wah_Cantt_Railway_Station", "Kamra_Road_Junction", "Railway_Link", 4.0);

sys.addRoad("Kamra_Road_Junction", "Taxila_Road", "Kamra_Main_Road", 3.0);

sys.addRoad("GT_Road_Wah_Cantt", "Wah_Nagar", "GT_Extension", 2.8);

sys.addRoad("Wah_Nagar", "Phase_3", "Nagar_Link", 3.1);

sys.addRoad("Phase_3", "Taxila_Road", "Outer_Ring_Road", 4.2);

sys.addRoad("Wah_Model_Town", "Wah_Nagar", "Town_Connector", 2.2);

sys.addRoad("Phase_1", "Phase_3", "Inner_Sector_Road", 3.3);

sys.addRoad("POF_Hospital", "GT_Road_Wah_Cantt", "Emergency_Route", 4.5);

sys.addRoad("Wah_Cantt_Railway_Station", "Wah_Model_Town", "Station_Link", 3.0);

sys.addRoad("Kamra_Road_Junction", "Phase_2", "Industrial_Road", 2.7);

sys.addRoad("Taxila_Road", "Taxila_City_Entry", "Highway_Stretch", 5.5);

sys.addRoad("Taxila_City_Entry", "Kamra_Road_Junction", "Entry_Road", 3.8);

sys.addRoad("Phase_2", "Wah_Nagar", "Sector_Connector", 2.9);

sys.addRoad("Wah_Nagar", "POF_Hospital", "Medical_Link_Road", 3.4);
sys.addHospital("POF_Hospital", "Phase_1_Wah");
sys.addHospital("Wah_General_Hospital", "GT_Road");
sys.addHospital("CMH_Wah", "Kamra_Road");
sys.addHospital("Al_Shifa", "Model_Town");
sys.addHospital("City_Clinic", "Phase_2");
sys.addHospital("Islamic_Medical", "Taxila_Road");
sys.addHospital("Emergency_Center", "POF_Sector");
sys.addHospital("Wah_Medical", "Wah_Nagar");
sys.addHospital("Civil_Taxila", "Taxila_City");
sys.addHospital("Private_Hospital", "Phase_3");

sys.addPoliceStation("Wah_Cantt_Central");
sys.addPoliceStation("Model_Town_Post");
sys.addPoliceStation("Phase_1_Post");
sys.addPoliceStation("Phase_2_Post");
sys.addPoliceStation("POF_Security");
sys.addPoliceStation("GT_Checkpost");
sys.addPoliceStation("Kamra_Police");
sys.addPoliceStation("Taxila_Station");
sys.addPoliceStation("Wah_Nagar_Post");
sys.addPoliceStation("Railway_Police");

sys.addComplaint(1, "Ali", "Road damage near GT Road");
sys.addComplaint(2, "Ahmed", "Traffic signal issue");
sys.addComplaint(3, "Sara", "Street lights off Phase 2");
sys.addTrafficSignal("GT_Road_Signal");
sys.addTrafficSignal("Phase_1_Signal");
sys.addTrafficSignal("Phase_2_Signal");
sys.addTrafficSignal("Hospital_Chowk");
sys.addTrafficSignal("Taxila_More");

    int choice;

    while(true)
    {
        cout << "\n️ WAH CANTT SMART CITY SYSTEM";
        cout << "\n1. Admin Login";
        cout << "\n2. User Login";
        cout << "\n3. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        if(choice == 1)
            adminMenu(sys);

        else if(choice == 2)
            userMenu(sys);

        else
            break;
    }

    return 0;
}