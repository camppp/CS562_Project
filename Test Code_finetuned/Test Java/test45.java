import com.ccnode.codegenerator.GeneratedFile;
import com.ccnode.codegenerator.GenCodeResponseHelper;
import com.ccnode.codegenerator.GenCodeUtil;
import com.ccnode.codegenerator.Logger;
import com.ccnode.codegenerator.LoggerWrapper;
import com.ccnode.codegenerator.OnePojoInfo;

public class CodeGenerator {

    private Logger logger;

    public CodeGenerator(Logger logger) {
        this.logger = new LoggerWrapper(logger);
    }

    public GeneratedFile generateCode(OnePojoInfo pojoInfo) {
        logger.info("Starting code generation for POJO: " + pojoInfo.getClassName());

        String code = GenCodeUtil.generateCode(pojoInfo);

        logger.info("Code generation completed for POJO: " + pojoInfo.getClassName());

        return new GeneratedFile(pojoInfo.getClassName() + ".java", code);
    }
}