
String instellingen()
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	switch (Odynummer){
		case 1://dod
			odyModule = 1;
			strActie = "4 op 1 ry";
		break;
		case 2://dor
			odyModule = 2;
			strActie = "schrijven";
		break;
		case 3://dom
			odyModule = 3;
			strActie = "dobbelsteen 1-3";
		break;
		case 4://dof
			odyModule = 4;
			strActie = "dobbelsteen 4-6";
		break;
				case 5://ded
					strActie = "e";
				break;
				case 6://der
					strActie = "f";
				break;
				case 7://dem
					strActie = "g";
				break;
				case 8://def
					strActie = "h";
				break;
				case 9://did
					strActie = "i";
				break;
				case 10://dir
					strActie = "j";
				break;
				case 11://dim
					strActie = "k";
				break;
				case 12://dif
					strActie = "l";
				break;
				case 13://dad
					strActie = "m";
				break;
				case 14://dar
					strActie = "n";
				break;
				case 15://dam
					strActie = "o";
				break;
				case 16://daf
					strActie = "p";
				break;
				case 17://rod
					strActie = "q";
				break;
				case 18://ror
					strActie = "r";
				break;
				case 19://rom
					strActie = "s";
				break;
				case 20://rof
					strActie = "t";
				break;
				case 21://red
					strActie = "u";
				break;
				case 22://rer
					strActie = "v";
				break;
				case 23://rem
					strActie = "w";
				break;
				case 24://ref
					strActie = "x";
				break;
				case 25://rid
					strActie = "y";
				break;
				case 26://rir
					strActie = "z";
				break;
				case 27://rim
					strActie = "1";
				break;
				case 28://rif
					strActie = "2";
				break;
				case 29://rad
					strActie = "3";
				break;
				case 30://rar
					strActie = "4";
				break;
				case 31://ram
					strActie = "5";
				break;
				case 32://raf
					strActie = "6";
				break;
				case 33://mod
					strActie = "7";
				break;
				case 34://mor
					strActie = "8";
				break;
				case 35://mom
					strActie = "9";
				break;
				case 36://mof
					strActie = "0";
				break;
				case 37://med
					strActie = "+";
				break;
				case 38://mer
					strActie = "-";
				break;
				case 39://mem
					strActie = "*";
				break;
				case 40://mef
					strActie = "/";
				break;
				case 41://mid
					strActie = "=";
				break;
				case 42://mir
					strActie = ".";
				break;
				case 43://mim
					strActie = ",";
				break;
				case 44://mif
					strActie = ",";
				break;
				case 45://mad
					strActie = "?";
				break;
				case 46://mar
					strActie = ";";
				break;
				case 47://mam
					strActie = ":";
				break;
				case 48://maf
					strActie = "au";
				break;
				case 49://fod
					strActie = "oo";
				break;
				case 50://for
					strActie = "oe";
				break;
				case 51://fom
					strActie = "aa";
				break;
				case 52://fof
					strActie = "ge";
				break;
				case 53://fed
					strActie = "ver";
				break;
				case 54://fer
					strActie = "sch";
				break;
				case 55://fem
					strActie = "st";
				break;
				case 56://fef
					strActie = "ing";
				break;
				case 57://fid
					strActie = "zw";
				break;
				case 58://fir
					strActie = "isch";
				break;
				case 59://fim
					strActie = "cht";
				break;
				case 60://fif
					strActie = " ";
				break;
				case 61://fad
				break;
				case 62://far
					
				break;
				case 63://fam
					
				break;
				case 64://faf
				break;
			}
return strActie;
}
//---------------------------------------------------------------------------

