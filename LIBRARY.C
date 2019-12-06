#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char data [ 20 ] ;
    char m [ 5 ] [ 20 ] ;
    int mcount ;
    struct node * next ;
} ;

struct node * library [ 26 ] ;

void add ( char * ) ;
void rent();
//void showrent();
int  search ( char * ) ;
void showbooks( ) ;
void clearprog( ) ;

void main( )
{
    char word [ 20 ] , ch ;
    int i ;

    clrscr( ) ;

    while ( 1 )
    {
	clrscr( ) ;
	printf ( "\n\t\t\xB2\xB2\xB2\xB2| Book Renting system |\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 1.Add Book \t\t\t\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 2.Find Book \t\t\t\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 3.Available Books \t\t\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 4.Rent Book \t\t\t\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 5.Rented Books \t\t\xB2\xB2\n" ) ;
	printf ( "\t\t\xB2\xB2 0.Exit \t\t\t\xB2\xB2 \n \t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" ) ;
	printf ( "\n\n\t\tYour Choice ") ;
	scanf ( "%d", &ch ) ;


	switch ( ch )
	{
	    case 1 :

		printf ( "\nEnter name of the book: " ) ;
		fflush ( stdin ) ;
		gets ( word ) ;
		add ( word ) ;

		break ;

	    case 2 :

		printf ( "\nEnter the book to search: " ) ;
		fflush ( stdin ) ;
		gets ( word ) ;
		i = search ( word ) ;
		if ( ! i )
		    printf ( "Book not found" ) ;
		getch( ) ;

		break ;

	    case 3 :

		showbooks( ) ;
		getch( ) ;

		break ;
	    case 4:
		   rent();
		   getch();

	    case 5:
		   //showrent();
		   getch();

	    case 0 :

		clearprog( ) ;
		exit ( 0 ) ;

	    default :

		printf ( "\nWrong Choice" ) ;
	}
    }
}

void add ( char * str )
{
    int i, j = toupper ( str [ 0 ] ) - 65 ;
    struct node * r, * temp = library [ j ], * q ;
    char mean [ 5 ] [ 20 ], ch = 'y' ;

    i = search ( str ) ;
    if ( i )
    {
	printf ( "\nBook already added." ) ;
	getch( ) ;
	return ;
    }
    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> data, str ) ;
    q -> next = NULL ;

    for ( i = 0 ; tolower ( ch ) == 'y' && i < 1 ; i++ )
    {
	fflush ( stdin ) ;
	printf ( "\n\nEnter the book ID : " ) ;
	gets ( mean [ i ] ) ;
	strcpy ( q -> m [ i ] , mean [ i ] ) ;
      /*	if ( i != 4 )
	    printf ( "\nAdd more meanings (y/n) " ) ;
	else
	    printf ( "You cannot enter more than 5 meanings." ) ;
	fflush ( stdin ) ;
	ch = getche( ) ; */
	getch();
    }

    q -> mcount = i ;
    if ( library [ j ] == NULL || strcmp ( library [ j ] -> data, str ) > 0 )
    {
	r = library [ j ] ;
	library [ j ] = q ;
	q -> next = r ;
	return ;
    }

    else
    {
	while ( temp != NULL )
	{
	    if ( ( strcmp ( temp -> data, str ) < 0 ) && ( ( strcmp ( temp -> next -> data, str ) > 0 ) ||
					    temp -> next == NULL ) )
	    {
		q -> next = temp -> next ;
		temp -> next = q ;
		return ;
	    }
	    temp = temp -> next ;
	}
    }
}
void rent ()
{  int t;
   char word[100];
printf("Choose Option:\n\t\t1.Enter the name of book.\n\t\t2.See avaiable books.");
scanf("%d",&t);
switch(t){
case 1:printf("Enter the name of book");
      fflush(stdin);
      gets(word);
      }}
int search ( char *str )
{
    struct node *n ;
    char temp1 [ 20 ] ;
    char temp2 [ 20 ] ;
    int i ;

    n = library [ toupper ( str [ 0 ] ) - 65 ] ;
    strcpy ( temp2, str ) ;
    strupr ( temp2 ) ;

    while ( n != NULL )
    {
	strcpy ( temp1, n -> data ) ;

	if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
	{
	    printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
	    for ( i = 1 ; i < n -> mcount ; i++ )
		printf ( "\n\t\t%s", n -> m [ i ] ) ;
	    return 1 ;
	}
	n = n -> next ;
    }
    return 0 ;
}

void showbooks( )
{

    struct node *n ;
    int i, j ;

    printf ( "BOOK\t\tBook ID\n" ) ;
    for ( i = 0 ; i <= 30 ; i++ )
	printf ( "-" ) ;


    for ( i = 0 ; i <= 25 ; i++ )
    {
	n = library [ i ] ;
	while ( n != NULL )
	{
	    printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
	    for ( j = 1 ; j < n -> mcount ; j++ )
		printf ( "\n\t\t%s", n -> m [ j ] ) ;
	    n = n -> next ;
	}
    }
}

void clearprog( )
{
    struct node *n, *t ;
    int i ;

    for ( i = 0 ; i <= 25 ; i++ )
    {
	n = library [ i ] ;
	while ( n != NULL )
	{
	    t = n -> next ;
	    free ( n ) ;
	    n = t ;
	}
    }
}
