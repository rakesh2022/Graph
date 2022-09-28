https://leetcode.com/problems/employee-importance/

class Solution
{
public:
  int getImportance(vector<Employee *> employees, int id)
  {
    unordered_map<int, Employee *> map;
    for (const auto element : employees)
      map[element->id] = element;
    
    return help(map, id);
  }

  int help(unordered_map<int, Employee *> &map, const int id)
  {
    auto sum = map[id]->importance;
    for (const auto element : map[id]->subordinates)
      sum += help(map, element);

    return sum;
  }
};
