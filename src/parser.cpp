#include <parser.hpp>

Node::Node(Token tk)
{
	_token = tk;
}

Node::Node(Token opToken, Node *left, Node *right)
{
	_left = left;
	_right = right;
	_token = opToken;
}

// TODO : Fix this shit
void displayNodes(Node* root)
{
	if (root != nullptr)
	{
		std::cout << "(";
		displayNodes(root->_left);
		std::cout << root->_token << " ";
		displayNodes(root->_right);
		std::cout << ")";
	}
}

Parser::Parser(std::vector<Token> tokens)
{
	_tokens = tokens;
	_tokenIndex = -1;
	advance();
}

void Parser::advance()
{
	_tokenIndex++;
	if (_tokenIndex < _tokens.size())
	{
		_currentToken = _tokens[_tokenIndex];
	}
	else
	{
		_currentToken = Token(TT_EOF);
	}
}

Node Parser::factor()
{
	Token tok = _currentToken;
	if (tok._type == TT_INT || tok._type == TT_FLOAT)
	{
		advance();
		return Node(tok);
	}
}

Node Parser::term()
{
	Node left = factor();
	while (_currentToken._type == TT_MUL || _currentToken._type == TT_DIV)
	{
		Token operatorToken = _currentToken;
		advance();
		Node right = factor();
		left = Node(operatorToken, &left, &right);
	}

	return left;
}

Node Parser::expr()
{
	Node left = term();
	while (_currentToken._type == TT_PLUS || _currentToken._type == TT_MINUS)
	{
		Token operatorToken = _currentToken;
		advance();
		Node right = term();
		left = Node(operatorToken, &left, &right);
	}

	return left;
}

Node Parser::parse()
{
	Node result = expr();
	return result;
}
