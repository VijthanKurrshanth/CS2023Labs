#include <iostream>
#include<vector>
#include <string>
using namespace std;


struct vertex{
    int label = 0;
    vector <vertex> neighbours{};
    int key =100;
    int pi =-1;

};

vertex* find(std::vector<vertex*> v, vertex value) {
  // Create an iterator to the beginning of the vector.
  auto begin = v.begin();

  // Create an iterator to the end of the vector.
  auto end = v.end();

  // Loop through the vector.
  while (begin != end) {
    // If the current element is equal to the value, return a pointer to the current element.
    if (begin->label == value->label) {
      return &*begin;
    }

    // Increment the iterator.
    begin++;
  }

  // The value was not found.
  return nullptr;
}

void removeValue(vector<vertex*> v, vertex value) {
  // Find the index of the value to be removed.
  vertex* it = find(v, value);

  // If the value was found, remove it from the vector.
    delete it;
}


vertex* extract_min(vector <vertex*> Q){
    vertex* min = Q.at(0);
    for (size_t i = 1; i < Q.size(); i++)
    {
        if (Q.at(i)->key < Q.at(0)->key)
        {
            min = Q.at(i);
        }
        
    }
    return min;
}

bool find(vector <vertex*> Q, vertex key){
    for (size_t i = 0; i < Q.size(); i++)
    {
        if (Q.at(i)->label == key.label)
        {
           return 1;
        }
        else{
            return 0;
        }
        
    }
    
}

void mst_prim(vector <vertex*> vertices, int(* weight_matrix)[6]){
    for (size_t i = 0; i < vertices.size(); i++)
    {
        vertices.at(i)->key = 100;
        vertices.at(i)->pi = -1;
    }
    
    vector <vertex*> Q = vertices;
    while (Q.size() != 0){
        vertex* u = extract_min(Q);
        removeValue(Q, u);
        for (size_t i = 0; i < u->neighbours.size(); i++)
        {
            int x =weight_matrix[u->neighbours.at(i).label][u->label];
            if ((find(Q, u->neighbours.at(i)) && weight_matrix[u->neighbours.at(i).label][u->label] < u->neighbours.at(i).key))
            {
                u->neighbours.at(i).pi = u->label;
                u->neighbours.at(i).key = weight_matrix[u->neighbours.at(i).label][u->label];
            }
            
        }
        
        
    }

    cout << "Edges of the MST are :"<< endl;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        cout << vertices.at(i)->label << "-" << vertices.at(i)->pi<< endl;

    }
    
    
}

int main(){

    int weight_matrix[6][6] = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
    int(* pointer)[6] = weight_matrix;

    vector <vertex*> vertices(6);

    for (size_t i = 0; i < 6; i++)
    {
        vertices[i] = new vertex;
        vertices[i]->label = i;

    }

    for (size_t i = 0; i < 6; i++)
    {
         switch(i) {
        case 0:
        {
            vertices[0]->neighbours.push_back(*vertices[1]);
            vertices[0]->neighbours.push_back(*vertices[5]);
            break;
        }

        case 1:
        {
            vertices[1]->neighbours.push_back(*vertices[0]);
            vertices[1]->neighbours.push_back(*vertices[2]);
            vertices[1]->neighbours.push_back(*vertices[3]);
            vertices[1]->neighbours.push_back(*vertices[4]);
            break;
        }

        case 2:
        {
            vertices[2]->neighbours.push_back(*vertices[1]);
            vertices[2]->neighbours.push_back(*vertices[3]);
            vertices[2]->neighbours.push_back(*vertices[5]);
            break;
        }

        case 3:
        {
            vertices[3]->neighbours.push_back(*vertices[1]);
            vertices[3]->neighbours.push_back(*vertices[2]);
            vertices[3]->neighbours.push_back(*vertices[4]);
            break;
        }

        case 4:
        {
            vertices[4]->neighbours.push_back(*vertices[1]);
            vertices[4]->neighbours.push_back(*vertices[3]);
            vertices[4]->neighbours.push_back(*vertices[5]);
            break;
        }

        case 5:
        {
            vertices[5]->neighbours.push_back(*vertices[0]);
            vertices[5]->neighbours.push_back(*vertices[2]);
            vertices[5]->neighbours.push_back(*vertices[4]);
            break;
        }
        }
    }
    
    mst_prim(vertices, pointer);

    
}

