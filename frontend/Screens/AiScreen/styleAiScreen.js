import { StyleSheet } from "react-native";
import { Colors } from "../../assets/cssVariables";

export default StyleSheet.create({
  container: { 
    flex: 1,
    backgroundColor:Colors.white,
    },
    button:{
      width:'30%',
      height:'8%',
      borderRadius: '15%',
      backgroundColor: Colors.darkGreen,
      display:'flex',
      justifyContent:'center',
      alignItems:'center',
      position:'absolute',
      bottom:'15%',
      left:'35%',
    },
      header:{
        fontWeight:900,
        color:Colors.yellow,
        fontSize:40,
        marginTop:'2%',
        width:'100%',
        textAlign:'center',
    },
    time:{
        marginTop:'5%',
        marginLeft:'1%',
        fontSize:20,
        color:Colors.darkGreen,
    }
});