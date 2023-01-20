extern crate pest;                                                                                                                                                                                   
#[macro_use]                                                                                                                                                                                         
extern crate pest_derive;                                                                                                                                                                            

use std::fs;
use std::io::Read;                                                                                                                                                                                         
use pest::Parser;                                                                                                                                                                                    
use pest::iterators::Pair;
use std::fs::File;                                                                                                                                                                           

// COMENZAMOS CON EL LLAMADO A NUESTRA GRAMATICA A TRABAJAR                                                                                                                                                                                               
#[derive(Parser)]                                                                                                                                                                                    
#[grammar = "grammar.pest"]                                                                                                                                                                            
struct IdentParser; 

// DESPLEGAMOS LOS DETALLES ANALISIS
fn print_pair(pair: &Pair<Rule>, hard_divider: bool) {
    println!("Terminal: {:?}", pair.as_span());
    println!("Entrada: {:?}", pair.as_str());
    if hard_divider {
        println!("{:=>60}", "");
    } else {
        println!("{:->60}", "");
    }
}

fn main() {

    //
    let doc_entrada = std::env::args().nth(2).expect("SELECCIONAR LA ESPECIFICACION DEL ARCHIVO");
    let mut cont = String::new();
    let mut arch = File::open(doc_entrada).unwrap();
    let mut nmb: String = String::new();
    arch.read_to_string(&mut cont).ok();
    cont = cont.replace('\n', " ");

    println!("SU ARCHIVO DE ENTRADA EN C:\n{:?}\n\n",cont.as_str());

    // 4. Parse el archivo de entrada
    let pair = IdentParser::parse(Rule::declaration, cont.as_str())
        .expect("NO ES POSIBLE REALIZAR EL ANALISIS SINTACTICO")
        .next().unwrap();

    print_pair(&pair, true);

    for inner_pair in pair.into_inner() {
 
        print_pair(&inner_pair, true);

        match inner_pair.as_rule() {
            Rule::idents =>  {
                for inner_inner_pair in inner_pair.into_inner() {
                    match inner_inner_pair.as_rule() {
                        Rule::ident => {
                            print_pair(&inner_inner_pair, false);
                        }
                        _ => unreachable!(),
                    }
                }
            }
            _ => unreachable!(),
        }
    }
}