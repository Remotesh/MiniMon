#pragma once

#pragma once


class Command {
public:
	Command()
	{
		entityId		= -1;
		entityCommand	= -1;
	};

	Command(int id, int command)
	{
		entityId		= id;
		entityCommand	= command;
	};

	int getId()
	{
		return entityId;
	};

	int getCommand()
	{
		return entityCommand;
	};

private:
	int entityId;
	int entityCommand;
};

class CommandQueue
{
public:
	CommandQueue()
	{
		Command* queue = new Command[queueSize];
	};

	void push(Command command)
	{
		Command* newQueue = new Command[queueSize + 1];
		
		for (int i = 0; i < queueSize; i++)
		{
			newQueue[i] = queue[i];
		}
		queue = newQueue;
		queue[queueSize] = command;

		queueSize++;
	};

	Command pop()
	{
		if (queueSize > 0)
		{
			Command returnValue = queue[0];

			Command* newQueue = new Command[(queueSize - 1)];
			for (int i = 1; i < queueSize; i++)
			{
				newQueue[i - 1] = queue[i];
			}

			queue = newQueue;

			queueSize--;

			return returnValue;
		}
		else
			return Command(-1, -1);
	};

	void insert(Command command, int pos)
	{
		if (pos > -1)
		{

			if (pos > queueSize)
			{
				push(command);
			}
			else
			{
				Command* newQueue = new Command[queueSize + 1];
				for (int i = 0; i < pos; i++)
				{
					newQueue[i] = queue[i];
				}
				newQueue[pos] = command;
				for (int i = pos; i < queueSize; i++)
				{
					newQueue[i + 1] = queue[i];
				}
				queue = newQueue;
				queueSize++;
			}
		}
	}

	Command fetch(int pos)
	{
		if (pos < queueSize)
		{
			return queue[pos];
		}
		else
			return Command(-1, -1);
	}

	int getSize()
	{
		return queueSize;
	};
	
private:
	Command* queue			= NULL;

	int queueSize			= 0;
	int currentLocation		= 0;
};