#include"Tree.hpp"

Tree::Tree()
{

	this->root = NULL;

}

Tree::Tree( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );

}

void Tree::print() const
{

	cout << endl;
	print_tree( this->root );

}

Tree& Tree::operator = ( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );

}