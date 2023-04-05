#include"Tree.hpp"

//Tree::Tree()
//{
//
//	this->root = NULL;
//
//}

Tree::Tree( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );

}

void Tree::print()
{

	print_tree( this->root );

}

Tree& Tree::operator = ( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );
	return *this;

}
 
bool Tree::insert( const int key )
{

	if(!this->contains(key)) this->root = add( this->root, key );
	return 1;

}

bool Tree::contains( int key ) const
{

	return presence( this->root, key );

}

bool Tree::erase( int key )
{

	this->root = delete_( this->root, key );
	return 1;

}

bool Tree::clear()
{

	clearing( this->root );
	return 1;

}

Tree::~Tree()
{

	this->clear();

}