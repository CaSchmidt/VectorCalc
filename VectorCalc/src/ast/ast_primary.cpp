/****************************************************************************
** Copyright (c) 2018, Carsten Schmidt. All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its
**    contributors may be used to endorse or promote products derived from
**    this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#include "ast/ast.h"

namespace AST {

  ////// RealConstant ////////////////////////////////////////////////////////

  RealConstant::RealConstant(const RealType value)
    : _value(value)
  {
  }

  RealConstant::~RealConstant()
  {
  }

  NodeType RealConstant::nodeType() const
  {
    return NodeType::RealConstant;
  }

  RealType RealConstant::value() const
  {
    return _value;
  }

  ////// UIntConstant ////////////////////////////////////////////////////////

  UIntConstant::UIntConstant(const UIntType value)
    : _value(value)
  {
  }

  UIntConstant::~UIntConstant()
  {
  }

  NodeType UIntConstant::nodeType() const
  {
    return NodeType::UIntConstant;
  }

  UIntType UIntConstant::value() const
  {
    return _value;
  }

  ////// Expression //////////////////////////////////////////////////////////

  Expression::Expression(Node *expr)
    : _expr(expr)
  {
  }

  Expression::~Expression()
  {
  }

  NodeType Expression::nodeType() const
  {
    return NodeType::Expression;
  }

  const Node *Expression::expr() const
  {
    return _expr.get();
  }

  ////// ExpressionList //////////////////////////////////////////////////////

  ExpressionList::ExpressionList()
    : _list()
  {
  }

  ExpressionList::~ExpressionList()
  {
  }

  NodeType ExpressionList::nodeType() const
  {
    return NodeType::ExpressionList;
  }

  void ExpressionList::append(Node *node)
  {
    _list.emplace_back(node);
  }

  const ExpressionListType& ExpressionList::list() const
  {
    return _list;
  }

  ////// Function ////////////////////////////////////////////////////////////

  Function::Function(Identifier *name, ExpressionList *args)
    : _name(name)
    , _args(args)
  {
  }

  Function::~Function()
  {
  }

  NodeType Function::nodeType() const
  {
    return NodeType::Function;
  }

  const IdentifierType& Function::name() const
  {
    return dynamic_cast<Identifier*>(_name.get())->value();
  }

  ExpressionList *Function::args() const
  {
    return dynamic_cast<ExpressionList*>(_args.get());
  }

  ////// Identifier //////////////////////////////////////////////////////////

  Identifier::Identifier(const IdentifierType& value)
    : _value(value)
  {
  }

  Identifier::~Identifier()
  {
  }

  NodeType Identifier::nodeType() const
  {
    return NodeType::Identifier;
  }

  const IdentifierType& Identifier::value() const
  {
    return _value;
  }

} // namespace AST
