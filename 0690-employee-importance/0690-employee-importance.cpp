/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (const auto &e: employees) {
            mp[e->id] = e;
        }

        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int eid = q.front();
            q.pop();

            Employee* emp = mp[eid];
            res += emp->importance;

            for (const auto& sid: emp->subordinates) {
                q.push(sid);
            }
        }

        return res;
    }
};