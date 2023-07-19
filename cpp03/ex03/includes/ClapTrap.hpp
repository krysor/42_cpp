#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>

class ClapTrap {


private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;


public:

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& clapTrap );
	ClapTrap&	operator=( const ClapTrap& clapTrap );
	~ClapTrap( void );

	virtual	void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	const std::string&	getName( void ) const;
	const unsigned int&	getHitPoints( void ) const;
	const unsigned int&	getEnergyPoints( void ) const;
	const unsigned int&	getAttackDamage( void ) const;

	void	setName( const std::string name );
	void	setHitPoints( unsigned int hitPoints );
	void	setEnergyPoints( unsigned int energyPoints );
	void	setAttackDamage( unsigned int  attackDamage );

	static	void	attackAndTakeDamage( ClapTrap& attacker, ClapTrap& victim );
};

#endif