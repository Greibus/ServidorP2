import java.util.Map.Entry;

public class Main {

	
	public static void main(String args[])
	{
		
		String test = "<Message><a>101</a> <b>0001</b> <c>1001</c> <d>11</d></Message>";
		 

        
        HuffmanDecoder huffDecoder = new HuffmanDecoder();

        
        
        
        String codedString = huffDecoder.Encode(test);
        
        
        System.out.println("huffman coded string: " + codedString);
        
        
        System.out.println("Decoded message: " + huffDecoder.Decode(codedString));
        
        
        System.out.println("codes to xml: " + huffDecoder.codesToXml());
        
        
        huffDecoder.xmlToCodes(test);
        
        
        System.out.println("Decoded message: " + huffDecoder.Decode("1010001100111"));
        
        
        
    }
		
	


	
	
		
}
	

