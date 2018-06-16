import java.util.Map.Entry;

public class Main {

	
	public static void main(String args[])
	{
		
		String test = "<Message><jsonMsg> this is an example for huffman encoding </jsonMsg> </Message>";
		 
        // we will assume that all our characters will have
        // code less than 256, for simplicity
        int[] charFreqs = new int[256];
        
        
        
        
        // read each character and record the frequencies
        for (char c : test.toCharArray()) {
            charFreqs[c]++;
            
        }
        
        HuffmanDecoder huffDecoder = new HuffmanDecoder();
 
        // build tree
        HuffmanTree tree = huffDecoder.buildTree(charFreqs);
 
        // print out results
        System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
        
        
        
        huffDecoder.printCodes(tree, new StringBuffer());
        
        
        
        String codedString = "";
        
        for (char c : test.toCharArray()) {
            
        	for (Entry<Character, String> entry : huffDecoder.CodeList.entrySet())
            {
                if(entry.getKey() == c) {
                	codedString += entry.getValue();
                }
            }
            
        }
        
        
        
        
        System.out.println("huffman coded string: " + codedString);
        
        
        System.out.println("Decoded message: " + huffDecoder.Decode(codedString));
        
        
    }
		
		
}
	
	

