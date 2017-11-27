#ifndef AST_ACTION_FACTORY
#define AST_ACTION_FACTORY

#include "clang/Tooling/Tooling.h"

#include "utility/file/FileRegister.h"

class CanonicalFilePathCache;
class ParserClient;

class ASTActionFactory
	: public clang::tooling::FrontendActionFactory
{
public:
	explicit ASTActionFactory(
		std::shared_ptr<ParserClient> client,
		std::shared_ptr<FileRegister> fileRegister,
		std::shared_ptr<CanonicalFilePathCache> canonicalFilePathCache
	);

	virtual ~ASTActionFactory();

	virtual clang::FrontendAction* create() override;

private:
	std::shared_ptr<ParserClient> m_client;
	std::shared_ptr<FileRegister> m_fileRegister;
	std::shared_ptr<CanonicalFilePathCache> m_canonicalFilePathCache;
};

#endif // AST_ACTION_FACTORY
