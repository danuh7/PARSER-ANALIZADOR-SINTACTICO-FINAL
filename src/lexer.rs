use std::{collections::HashMap, io::Read};
use std::fs::File;
use regex_automata::{MultiMatch, dfa::regex::Regex};



//EMPEZAMOS POR LA CELCARACION DE TABLAS QUE SERÁN DE AYUDA AL REALIZAR EL ANALISIS LEXICO Y SINTACTICO

#[derive(Debug)]
struct Token{
    map: HashMap<u32, String>,
    table: HashMap<String, String>
}


impl Token {
    fn new(entries:String) -> Result<Token, std::io::Error>{
        
        let mut id:u32 = 0;
        
        let mut map: HashMap<u32, String> = HashMap::new();
        let mut table: HashMap<String, String> = HashMap::new();


        println!("{}", entries);

        for c in entries.split("'") {
            if c.is_empty(){
                break;
            }
            else{
                let mut values = c.split(':');

                let key = values.next().expect("No Key");
                let val = values.next().expect("No Value");
                
                table.insert(String::from(key), String::from(val));
                map.insert(id, c.to_owned());
                
                id = id + 1;
            }
        }
        Ok(Token {map, table})
    }
    
}

//INICIO DE LA FASE DE COMPILACION
fn comp(doc:String, _exe:String){

    let mut cont = String::new();
    let mut arch = File::open(doc).unwrap();
    let mut nmb: String = String::new();
    let mut nmb_prov: String = String::new();
    let mut palabra:String = String::new();

    arch.read_to_string(&mut cont).ok();
    cont = cont.replace('\n', " ");
    cont = cont.replace('{', " {");
    cont = cont.replace('(', " (");


    //EL ANALIZADOR LEXICO SERÁ LA PRIMERA FASE DE ESTE PROGRAMA
    println!("Su archivo en C: \n");
    println!("{}",cont);
    println!("\nCOMENZANDO EL ANALISIS: ");
    for character in cont.chars(){
        if  character.is_ascii_whitespace() || character == ';'{
            if !palabra.is_empty(){
                nmb_prov = analizer(palabra);
                nmb = format!("{}{}'",nmb,nmb_prov);
                palabra = String::new();
            }  
        }   
        else {
            palabra.push(character);
        }
    }

    if  !nmb_prov.is_empty(){
        let tokens = Token::new(nmb).expect("ERROR EN EL LEXER(ANALIZADOR LEXICO)");
        
        println!("\n SE HA OBTENIDO");
        println!("\Tokenized: {:#?}", tokens); 
    }
    else{

    }


}

//COMENZAMOS CON LA CLASIFICACION DE TOKEN
fn analizer(word:String) -> String{

    let mut id = String::new();

    let pch = word.chars().next().unwrap();

    println!("Palabra: {}, primera letra:{}", word, pch);
    

    match pch{
        '0' ..= '9' => id = isNumber(&word),
        'A'..='Z' | 'a'..='z' => id = isWord(&word),
        '<' | '>' | '=' => id = isOpRel(&word),
        _ => println!("ERROR, LA EXPRESION INGRESADA NO HA SIDO RECONOCIDA: {}", word)
    }

    return format!("{}:{}",word, id);
}

fn isNumber(word:&String) -> String{
    let re = Regex::new(r"{0-9}+.{0-9}?E{+-}?[{0-9}+]?");
    let check = 0;
    return  "Numero".to_string();
}

fn isWord(word:&String) -> String{
    let re = Regex::new(r"[{a-z}|{A-Z}_][[{a-z}|{A-Z}_]|{0-9}]*");
    return "Palabra".to_string();
}

fn isOpRel(word:&String)-> String {
    let re = Regex::new(r"<|>|<=|=>|==|<>");
    return "Operacion Relacional".to_string();    
}


fn main() {

    let doc_entrada = std::env::args().nth(2).expect("SELECCIONA LA ESPECIFICACION DE SU ARCHIVO DE ENTRADA");
    let action: String = std::env::args().nth(1).expect("SELECCIONA LA ACCION A REALIZARr");


    match action.as_ref() {
        "-c" => {
            comp(doc_entrada, "a".to_owned()); 
        },
        "-o" => {
            let doc_salida = std::env::args().nth(3).expect("INGRESE UN NOMBRE");
            comp(doc_entrada, doc_salida);
        },
        _ => println!("INSTRUCCION NO VALIDA") 
    }
}