#include <iostream>

#ifndef SASS_NODE_INCLUDED
#include "node.hpp"
#endif

#include "node_factory.hpp"

int main()
{
  using namespace Sass;
  using namespace std;
  
  cout << sizeof(Node_Impl*) << endl;
  cout << sizeof(Node) << endl;
  cout << sizeof(Node_Impl) << endl << endl;
  
  Node_Factory new_Node = Node_Factory();
  
  Node interior(new_Node(Node::block, "", 0, 3));
  
  cout << interior.size() << endl;
  cout << interior.has_children() << endl;
  cout << interior.should_eval() << endl << endl;
  
  Node num(new_Node("", 0, 255, 123, 32));
  Node num2(new_Node("", 0, 255, 123, 32));
  Node num3(new_Node("", 0, 255, 122, 20, .75));
  
  cout << num.size() << endl;
  cout << num.has_children() << endl;
  cout << num.has_statements() << endl << endl;
  
  cout << num[1].is_numeric() << endl;
  cout << num[1].numeric_value() << endl << endl;
  
  cout << (num == num2) << endl;
  cout << (num == num3) << endl << endl;
  
  cout << (num3[2] < num2[2]) << endl;
  cout << (num2[3] < num3[3]) << endl << endl;
  
  cout << (num2[2] >= num3[2]) << endl;
  cout << (num2[3] != num3[3]) << endl << endl;

  Node num4(new_Node(num3));
  cout << num3[3].numeric_value() << endl;
  cout << num4[3].numeric_value() << endl;
  num4[3] = new_Node("", 0, 0.4567);
  cout << num3[3].numeric_value() << endl;
  cout << num4[3].numeric_value() << endl;

  new_Node.free();
  
  return 0;
}