#pragma once
#include "pch.h"
#include "Sequence.h"

unsigned int Sequence::_current;

Sequence::Sequence()
{

}

unsigned int Sequence::getNext()
{
	return (++_current);
}