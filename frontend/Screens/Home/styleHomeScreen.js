import { StyleSheet } from "react-native";
import { Colors } from "../../assets/cssVariables"; 

export default StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  boxRecipe: {
    backgroundColor:Colors.white,
    width: '100%',
    height: '80%',
    bottom:'10%',

    display:"flex",
    position:'absolute',
    margin: 'auto',

  },
  textHeader:{
    fontSize: 40,
    position: 'absolute',
    fontWeight:900,
    color:Colors.yellow,
    marginTop: '7%',

  },
  text:{
    fontSize:25,
    fontWeight:'600',
    marginBottom:'5%',
    marginTop:'3%',
    marginLeft:'1%',
    textAlign:'center',
  },
  textEntry:{
    fontSize:20,
    fontWeight:'300',
    marginTop:'3%',
    textAlign:'center',
    fontWeight:'400',
  },
  header:{
    width:'100%',
    height:'10%',
    backgroundColor:Colors.darkGreen,

    position:'absolute',
    display:'flex',
    justifyContent:'center',
    alignItems:'center',
    top:0,
  }
});
