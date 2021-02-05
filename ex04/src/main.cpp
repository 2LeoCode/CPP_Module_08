/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:43:16 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 21:40:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <postfix.hpp>

void checkPar(std::queue<Token *> tokens)
{
	uint32_t parOpen = 0, parClose = 0;
	Token * previous = nullptr;

	if (dynamic_cast<Op *>(tokens.front()))
		throw (std::runtime_error("Invalid Expression"));
	while (!tokens.empty())
	{
		if (dynamic_cast<ParOpen *>(tokens.front())) parOpen++;
		else if (dynamic_cast<ParClose *>(tokens.front())) parClose++;
		else if (dynamic_cast<Op *>(tokens.front()) &&
		((tokens.size() == 1) ||
		(previous && (dynamic_cast<Op *>(previous) || dynamic_cast<ParOpen *>(previous)))))
			throw (std::runtime_error("Invalid Expression"));
		previous = tokens.front();
		tokens.pop();
	}
	if (parOpen > parClose) throw (std::runtime_error("Missing closing parenthese(s)"));
	if (parOpen < parClose) throw (std::runtime_error("Missing opening parenthese(s)"));
}

int it_atoi(std::string::iterator begin, std::string::iterator end)
{
	long nb = 0;
	long ng = 1;

	while (begin != end && std::isspace(*begin))
		begin++;
	if ((begin != end) && ((*begin == '-') || (*begin == '+')))
		ng -= 2 * (*begin == '-'), begin++;

	while ((begin != end) && std::isdigit(*begin))
		nb = 10 * nb + (*begin - '0'), begin++;

	return (static_cast<int>(nb * ng));
}

void displayQueue(std::queue<Token *> queue)
{
	while (!queue.empty())
		std::cout << *queue.front() << ' ', queue.pop();
	std::cout << std::endl;
}

void displayList(std::list<Token *> list)
{
	while (!list.empty())
		std::cout << *list.front() << ' ', list.pop_front();
	std::cout << std::endl;
}

void displayStack(std::stack<int> stack)
{
	while (!stack.empty())
		std::cout << stack.top() << ' ', stack.pop();
}

void mergeLists(std::list<Token *> & l1, std::list<Token *> & l2)
{
	for (; !l2.empty(); l2.pop_front())
		l1.push_back(l2.front());
}

std::list<Token *> get_postfix(std::queue<Token *> queue)
{
	std::list<Token *> postfix;
	char operation = '0';

	while (!queue.empty() && !dynamic_cast<ParClose *> (queue.front()))
	{
		if (dynamic_cast<ParOpen *> (queue.front()))
		{
			int pOpen = 1, pClose = 0;
			queue.pop();
			std::list<Token *> tmp = get_postfix(queue);
			mergeLists(postfix, tmp);
			if (operation != '0') postfix.push_back(new Op(operation)), operation = '0';
			for (; !queue.empty() && (pOpen != pClose); queue.pop())
				if (dynamic_cast<ParOpen *> (queue.front())) pOpen++;
				else if (dynamic_cast<ParClose *> (queue.front())) pClose++;
			continue ;
		}
		if (dynamic_cast<Op *> (queue.front()))
			operation = dynamic_cast<Op *> (queue.front())->getOp();
		if (dynamic_cast<Num *> (queue.front()))
		{
			postfix.push_back(queue.front());
			if (operation != '0') postfix.push_back(new Op(operation)), operation = '0';
		}
		queue.pop();
	}
	return (postfix);
}

void executePostfix(std::list <Token *> tokens)
{
	std::stack<int> opStack;
	Op * op;

	for (; !tokens.empty(); tokens.pop_front())
	{
		std::cout << "[ " << *tokens.front() << " \t| ";
		if ((op = dynamic_cast<Op *>(tokens.front())) != nullptr)
			op->doOp(opStack);
		else
		{
			std::cout << "OP Push";
			opStack.push(dynamic_cast<Num *>(tokens.front())->number());
		}
		std::cout << "\t| ST ";
		displayStack(opStack);
		std::cout << ']' << std::endl;
	}
	std::cout << "Result : " << opStack.top() << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2) { std::cerr << "Usage: ./postfix <expression>" << std::endl; return (-1); }

	std::string expr(argv[1]);
	std::queue<Token *> tokenQueue;
	for (std::string::iterator it = expr.begin(); it != expr.end(); it++)
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
		{
			tokenQueue.push(new Num(it_atoi(it, expr.end())));
			while ((it + 1) != expr.end() && std::isdigit(*(it + 1)))
				it++;
		}
		else if (*it == '(')
			tokenQueue.push(new ParOpen);
		else if (*it == ')')
			tokenQueue.push(new ParClose);
		else try { tokenQueue.push(new Op(*it)); } catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	try { checkPar(tokenQueue); } catch (std::exception & e) { std::cerr << e.what() << std::endl; return (-1); }
	std::cout << "Tokens: ";
	displayQueue(tokenQueue);
	std::list<Token *> postfix_tokens = get_postfix(tokenQueue);
	for (; !tokenQueue.empty(); tokenQueue.pop())
		if (dynamic_cast<ParOpen *>(tokenQueue.front())
		|| dynamic_cast<ParClose *>(tokenQueue.front()))
			delete tokenQueue.front();
	std::cout << "Postfix: ";
	displayList(postfix_tokens);
	executePostfix(postfix_tokens);
	for (; !postfix_tokens.empty(); postfix_tokens.pop_front())
		delete postfix_tokens.front();
	return (0);
}
